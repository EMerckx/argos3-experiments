/**
 * This was adapted from the argos3 examples repository, with credit to Dr. Carlo Pinciroli.
 * See <a href="https://github.com/ilpincy/argos3-examples">ilpincy/argos3-examples</a> (accessed May 28th, 2016).
 *
 * @author Ewout Merckx - <ewoutmerckx.pro@gmail.com>
 */

/* Include the controller definition */
#include "eyebot_diffusion.h"
/* Function definitions for XML parsing */
#include <argos3/core/utility/configuration/argos_configuration.h>
/* Function definitions for logging */
#include <argos3/core/utility/logging/argos_log.h>

/****************************************/
/****************************************/

/* Altitude to circle to move along the circle */
static const Real ALTITUDE = 1.0f;

/* Tolerance for the distance to a target point to decide to do something else */
static const Real PROXIMITY_TOLERANCE = 0.01f;

/* The size of movement by the eye-bot */
static const Real STEP_SIZE = 0.05f;

/* The angle range for collision or not */
static const CRadians ANGLE_RANGE = CRadians::PI_OVER_FOUR;

/* Vector length for collision or not */
static const Real VECTOR_LENGTH = 0.05f;

/* Time to land the robot */
static const UInt16 LAND_TIME = 1000; 

/****************************************/
/****************************************/

CEyeBotDiffusion::CEyeBotDiffusion() :
    m_pcPosAct(NULL),
    m_pcPosSens(NULL),
    m_pcProxSens(NULL) {}

/****************************************/
/****************************************/

void CEyeBotDiffusion::Init(TConfigurationNode& t_node) {
    m_pcPosAct    = GetActuator<CCI_QuadRotorPositionActuator>("quadrotor_position");
    m_pcPosSens   = GetSensor  <CCI_PositioningSensor        >("positioning"       );
    m_pcProxSens  = GetSensor  <CCI_EyeBotProximitySensor    >("eyebot_proximity"  );

    /*
     * Initialize the state variables of the behavior
     */
    Reset();
}

/****************************************/
/****************************************/

void CEyeBotDiffusion::ControlStep() {
    m_unCounter++;

    switch(m_eState) {
        case STATE_START:
            TakeOff();
            break;
        case STATE_TAKE_OFF:
            TakeOff();
            break;
        case STATE_MOVE:
            Move();
            break;
        case STATE_LAND:
            Land();
            break;
        default:
            LOGERR << "[BUG] Unknown robot state: " << m_eState << std::endl;
    }
}

/****************************************/
/****************************************/

void CEyeBotDiffusion::Reset() {
    /* Start the behavior */
    m_eState = STATE_START;

    /* Set the initial diffusion vector so the eye-bot moves */
    m_cDiffusionVector = CVector2(STEP_SIZE, 0.0f);

    /* Counter to land */
    m_unCounter = 0;
}

/****************************************/
/****************************************/

void CEyeBotDiffusion::TakeOff() {
    if(m_eState != STATE_TAKE_OFF) {
        /* State initialization */
        m_eState = STATE_TAKE_OFF;
        m_cTargetPos = m_pcPosSens->GetReading().Position;
        m_cTargetPos.SetZ(ALTITUDE);
        m_pcPosAct->SetAbsolutePosition(m_cTargetPos);
    }
    else {
        if(Distance(m_cTargetPos, m_pcPosSens->GetReading().Position) < PROXIMITY_TOLERANCE) {
            /* State transition */
            Move();
        }
    }
}

/****************************************/
/****************************************/

void CEyeBotDiffusion::Move() {
    if(m_eState != STATE_MOVE) {
        /* State initialization */
        m_eState = STATE_MOVE;
    }

    /* Specify the movement vector for diffusion */
    CalculateDiffusionVector();
    /* Use the calculated diffusion vector to set the relative position */
    m_pcPosAct->SetRelativePosition(CVector3(
        m_cDiffusionVector.GetX(),
        m_cDiffusionVector.GetY(),
        0.0f));

    if(m_unCounter > LAND_TIME){
        /* State transition */
        Land();
    }
}

/****************************************/
/****************************************/

void CEyeBotDiffusion::Land() {
    if(m_eState != STATE_LAND) {
        /* State initialization */
        m_eState = STATE_LAND;
        m_cTargetPos = m_pcPosSens->GetReading().Position;
        m_cTargetPos.SetZ(0.0f);
        m_pcPosAct->SetAbsolutePosition(m_cTargetPos);
    }
}

/****************************************/
/****************************************/

void CEyeBotDiffusion::CalculateDiffusionVector() {
    /* Get readings from proximity sensor */
    const CCI_EyeBotProximitySensor::TReadings& tProxReads = m_pcProxSens->GetReadings();
    /* Sum them together */
    CVector2 cDiffusionVector;
    for(size_t i = 0; i < tProxReads.size(); ++i) {
        cDiffusionVector += CVector2(tProxReads[i].Value, tProxReads[i].Angle);
    }

    /* If the angle is between the range and close enough, 
     * the current movement will result in a collision */
    if(cDiffusionVector.Angle() > m_cDiffusionVector.Angle() - ANGLE_RANGE && 
        cDiffusionVector.Angle() < m_cDiffusionVector.Angle() + ANGLE_RANGE &&
        cDiffusionVector.Length() > VECTOR_LENGTH){

        /* Normalize the vector and resize it conform to the step size */
        cDiffusionVector.Normalize();
        cDiffusionVector *= STEP_SIZE;

        /* When collision, the movement of the eye-bot equals to the reversed vector to the object */
        m_cDiffusionVector = -cDiffusionVector;
    }
}

/****************************************/
/****************************************/

REGISTER_CONTROLLER(CEyeBotDiffusion, "eyebot_diffusion_controller")
