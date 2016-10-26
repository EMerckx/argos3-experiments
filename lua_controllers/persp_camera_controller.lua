-----------------------------------------------------
-- @author Ewout Merckx - <ewoutmerckx.pro@gmail.com>
-----------------------------------------------------

-- global variables
amount_steps = 0
max_steps = 100

-- initialization 
function init()
    -- set the speed of the robot to zero
    robot.wheels.set_velocity(0,0)

    -- initialize the amount of steps
    amount_steps = 0

    -- enable the perspective camera
    robot.colored_blob_perspective_camera.enable()
end

-- actions for each step
function step()
    -- as long as we don't take too many steps, go forward
    -- else stop moving
    if amount_steps < max_steps then
        robot.wheels.set_velocity(-5,5)
        amount_steps = amount_steps + 1
    else
        robot.wheels.set_velocity(0,0)
    end

    -- each step, read the perspective camera
    read_persp_camera()
end

-- reinitialize the controller
function reset()
    -- set the speed of the robot to zero
    robot.wheels.set_velocity(0,0)

    -- initialize the amount of steps
    amount_steps = 0
end

function destroy()
    -- disable the perspective camera
    robot.colored_blob_perspective_camera.disable()
end

---------------------------------------------------------------------

-- read the perspective camera and logs the readings
function read_persp_camera()

    -- log the amount of readings
    log("Size: " ..
        #robot.colored_blob_perspective_camera)

    -- iterate the readings and log the values
    for i = 1, #robot.colored_blob_perspective_camera do
        msg = "entr: " .. i ..
            " x: " .. 
            robot.colored_blob_perspective_camera[i].x ..
            " y: " ..
            robot.colored_blob_perspective_camera[i].y ..
            " R: " ..
            robot.colored_blob_perspective_camera[i].color.red ..
            " G: " ..
            robot.colored_blob_perspective_camera[i].color.green ..
            " B: " ..
            robot.colored_blob_perspective_camera[i].color.blue;

        log(msg)
    end
end
