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
    -- each step, take a different color
    create_key_value_table()
end

-- reinitialize the controller
function reset()
end

function destroy()
    -- put your code here
end

---------------------------------------------------------------------

-- creates a table, adds some values to it
-- and afterwards, log the content of the table
function create_key_value_table()

	t = {
      ["fb34"] = 12, ["fb02"] = 24,
      ["fb11"] = 03, ["fb09"] = 19
    }

    for key,value in pairs(t) do 
    	log(key .. " -> " .. value)
    end

    log("--------------------")

end
