-----------------------------------------------------
-- @author Ewout Merckx - <ewoutmerckx.pro@gmail.com>
-----------------------------------------------------

-- global variables
amount_steps = 0
max_steps = 50

-- initialization 
function init()
    -- set the speed of the robot to zero
    robot.wheels.set_velocity(0,0)

    -- initialize the amount of steps
    amount_steps = 0
end

-- actions for each step
function step()
    -- as long as we don't take too many steps, go forward
    -- else stop moving
    if amount_steps < max_steps then
        robot.wheels.set_velocity(5,5)
        amount_steps = amount_steps + 1
    else
        robot.wheels.set_velocity(0,0)
    end

    -- each step, read the light sensors
    read_light_sensor()
end

-- reinitialize the controller
function reset()
    init()
end

function destroy()
    -- put your code here
end

---------------------------------------------------------------------

-- reads every light sensor and logs them
function read_light_sensor()
    -- iterate over the light sensors
    for index = 1, #robot.light do
        log(index .. " -> " .. robot.light[index].value)
    end
end
