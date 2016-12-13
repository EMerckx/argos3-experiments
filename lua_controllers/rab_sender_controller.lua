-----------------------------------------------------
-- @author Ewout Merckx - <ewoutmerckx.pro@gmail.com>
-----------------------------------------------------

-- global variables

-- initialization 
function init()
    -- set the speed of the robot to zero
    robot.wheels.set_velocity(0,0)
end

-- actions for each step
function step()
    -- each step, send a message
    send_message()
end

-- reinitialize the controller
function reset()
end

function destroy()
    -- put your code here
end

---------------------------------------------------------------------

-- sends the message "2" via range and bearing
function send_message()
    index = 1
    message = 2
    robot.range_and_bearing.set_data(index, message)
    log("I'm sending: " .. message)
end
