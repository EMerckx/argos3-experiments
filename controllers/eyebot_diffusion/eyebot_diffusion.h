/**
 * This was adapted from the argos3 examples repository, with credit to Dr. Carlo Pinciroli.
 * See <a href="https://github.com/ilpincy/argos3-examples">ilpincy/argos3-examples</a> (accessed May 28th, 2016).
 *
 * @author Ewout Merckx - <ewoutmerckx.pro@gmail.com>
 */

#ifndef EYEBOT_DIFFUSION_H
#define EYEBOT_DIFFUSION_H

/*
 * Include some necessary headers.
 */
/* Definition of the CCI_Controller class. */
#include <argos3/core/control_interface/ci_controller.h>
/* Definition of the quadrotor positioning actuator */
#include <argos3/plugins/robots/generic/control_interface/ci_quadrotor_position_actuator.h>
/* Definition of the positioning sensor */
#include <argos3/plugins/robots/generic/control_interface/ci_positioning_sensor.h>
/* Definition of the proximity sensor */
#include <argos3/plugins/robots/eye-bot/control_interface/ci_eyebot_proximity_sensor.h>

using namespace argos;

class CEyeBotDiffusion : public CCI_Controller {

public:

    /* Class constructor. */
    CEyeBotDiffusion();

    /* Class destructor. */
    virtual ~CEyeBotDiffusion() {}

    /*
     * This function initializes the controller.
     * The 't_node' variable points to the <parameters> section in the XML
     * file in the <controllers><eyebot_circle_controller> section.
     */
    virtual void Init(TConfigurationNode& t_node);

    /*
     * This function is called once every time step.
     * The length of the time step is set in the XML file.
     */
    virtual void ControlStep();

    /*
     * This function resets the controller to its state right after the
     * Init().
     * It is called when you press the reset button in the GUI.
     */
    virtual void Reset();

    /*
     * Called to cleanup what done by Init() when the experiment finishes.
     * In this example controller there is no need for clean anything up,
     * so the function could have been omitted. It's here just for
     * completeness.
     */
    virtual void Destroy() {}

private:

    /*
     * Takes off the robot.
     */
    void TakeOff();

    /*
     * Moves the robot.
     */
    void Move();
    
    /*
     * Lands the robot.
     */
    void Land();

    /*
     * Calculates the movement vector for the robot.
     */
    void CalculateDiffusionVector();

private:

    /* Current robot state */
    enum EState {
        STATE_START = 0,
        STATE_TAKE_OFF,
        STATE_MOVE,
        STATE_LAND
    };

private:

    /* Pointer to the quadrotor position actuator */
    CCI_QuadRotorPositionActuator* m_pcPosAct;
    /* Pointer to the positioning sensor */
    CCI_PositioningSensor* m_pcPosSens;
    /* Pointer to the proximity sensor */
    CCI_EyeBotProximitySensor* m_pcProxSens;

    /* Current robot state */
    EState m_eState;
    /* Current target position */
    CVector3 m_cTargetPos;
    /* Current relative movement vector */
    CVector2 m_cDiffusionVector;

    /* Counter for the time */
    UInt16 m_unCounter;
};

#endif
