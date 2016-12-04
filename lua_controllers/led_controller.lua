-----------------------------------------------------
-- @author Ewout Merckx - <ewoutmerckx.pro@gmail.com>
-----------------------------------------------------

-- global variables
index = 0
colors = { 
    {255,255,255},  -- white
    {0,0,0},        -- black
    {255,0,0},      -- red
    {0,255,0},      -- green
    {0,0,255},      -- blue
    {255,0,255},    -- magenta
    {0,255,255},    -- cyan
    {255,255,0},    -- yellow
}

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
    change_led_color()
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

-- calculates the next index in the color table
-- after that, the specified color is set to the leds
function change_led_color()
    -- calculate next index
    index = (index % #colors) + 1

    log("Color index: " .. index)

    -- get the specified color from the table
    new_color = colors[index]

    -- set color of the leds
    robot.leds.set_all_colors(new_color[1], new_color[2], new_color[3])
end
