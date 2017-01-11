-----------------------------------------------------
-- @author Ewout Merckx - <ewoutmerckx.pro@gmail.com>
-----------------------------------------------------

-- global variables

-- initialization 
function init()
    -- init the index
    index = 0

    -- set the speed of the robot to zero
    robot.wheels.set_velocity(0,0)
end

-- actions for each step
function step()
    -- each step, log the recieved messages
    receive_messages()
end

-- reinitialize the controller
function reset()
    -- reinit the index
    index = 0
end

function destroy()
    -- put your code here
end

---------------------------------------------------------------------

-- receives a message
function receive_message()
    if robot.range_and_bearing[1].data then
        message = robot.range_and_bearing[1].data
        log("I'm receiving: " .. message[1])
    end
end

-- receives all messages
function receive_messages()
    msg = " - "
    for i = 1, #robot.range_and_bearing do
        for j = 1, #robot.range_and_bearing[i].data do
            msg = msg .. " " .. robot.range_and_bearing[i].data[j]
        end
        msg = msg .. " -"
    end
    log("I'm receiving" .. msg)
end
