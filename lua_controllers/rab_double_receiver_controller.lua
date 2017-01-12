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
    -- each step, log the received messages
    receive_messages()

    -- calculate the float number from the received messages
    number = calculate_float_number(1)
    log("Calculated number: " .. number)
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

---------------------------------------------------------------------

function calculate_float_number(index)
    float_chunk_1 = calculate_decimal(index, 2)
    float_chunk_2 = calculate_decimal(index, 5)
    float_chunk_3 = calculate_decimal(index, 8)

    return float_chunk_1 + float_chunk_2 +  float_chunk_3
end

---------------------------------------------------------------------

function calculate_decimal(index, begin_index)
    number = get_message(index, begin_index)
    is_exp_neg_flag = get_message(index, begin_index + 1)
    exponent = get_message(index, begin_index + 2)

    return calculate_decimal_from_chunk(number, is_exp_neg_flag, exponent)
end

function calculate_decimal_from_chunk(number, is_exp_neg_flag, exponent)
    multiplier = get_multiplier(is_exp_neg_flag, exponent)
    return number * multiplier
end

---------------------------------------------------------------------

-- returns 10 ^ exponent
function get_multiplier(is_exp_neg_flag, exponent)
    multiplier = 1
    for i = 1, exponent do
        multiplier = multiplier * 10
    end

    if is_exp_neg_flag == 1 then 
        multiplier = 1 / multiplier
    end

    return multiplier
end

---------------------------------------------------------------------

function get_message(index_1, index_2)
    msg = 0
    if index_1 <= #robot.range_and_bearing then
        if index_2 <= #robot.range_and_bearing[index_1].data then
            msg = robot.range_and_bearing[index_1].data[index_2]
        end
    end
    return msg
end