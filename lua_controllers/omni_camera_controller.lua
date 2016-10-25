-----------------------------------------------------
-- @author Ewout Merckx - <ewoutmerckx.pro@gmail.com>
-----------------------------------------------------

-- Put your global variables here

-- initialization 
function init()
    -- set the speed of the robot to zero
    robot.wheels.set_velocity(0,0)

    robot.colored_blob_omnidirectional_camera.enable()
end

-- actions for each step
function step()
    -- each step, read the light sensors
    read_front_camera()
end

-- reinitialize the controller
function reset()
end

-- when the robot gets destroyed
function destroy()
    robot.colored_blob_omnidirectional_camera.disable()
end

---------------------------------------------------------------------

-- reads the camera sensor and logs the values
function read_front_camera()

    -- log the amount of readings
    log("Size: " ..
        #robot.colored_blob_omnidirectional_camera)

    -- iterate the readings and log the values
    for i = 1, #robot.colored_blob_omnidirectional_camera do
        msg = "entr: " .. i ..
            " dist: " .. 
            robot.colored_blob_omnidirectional_camera[i].distance ..
            " angl: " ..
            robot.colored_blob_omnidirectional_camera[i].angle ..
            " R: " ..
            robot.colored_blob_omnidirectional_camera[i].color.red ..
            " G: " ..
            robot.colored_blob_omnidirectional_camera[i].color.green ..
            " B: " ..
            robot.colored_blob_omnidirectional_camera[i].color.blue;

        log(msg)
    end

end
