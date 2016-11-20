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

        -- each step, log a random number
        log_random_number()

        amount_steps = amount_steps + 1
    end
end

-- reinitialize the controller
function reset()
    init()
end

function destroy()
    -- put your code here
end

---------------------------------------------------------------------

-- generates a random number and logs it
function log_random_number()
    -- generate random number -> [0,1[
    rand = robot.random.uniform()

    log("Random number: " .. rand)
end
