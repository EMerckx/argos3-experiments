-----------------------------------------------------
-- @author Ewout Merckx - <ewoutmerckx.pro@gmail.com>
-----------------------------------------------------

-- global variables
number = 0

-- initialization 
function init()
    -- init the number
    number = 0

    -- set the speed of the robot to zero
    robot.wheels.set_velocity(0,0)
end

-- actions for each step
function step()
    -- each step, use a different number
    change_number()
end

-- reinitialize the controller
function reset()
    -- reinit the index
    number = 0
end

function destroy()
    -- put your code here
end

---------------------------------------------------------------------

-- changes the number and logs it
function change_number()
    -- generate new number
    number = math.floor(robot.random.uniform() * 10)

    log("Number in controller: " .. number)
end
