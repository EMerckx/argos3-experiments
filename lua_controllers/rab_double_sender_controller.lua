-----------------------------------------------------
-- @author Ewout Merckx - <ewoutmerckx.pro@gmail.com>
-----------------------------------------------------

-- global variables
FLOAT_NUMBER = 1234.567

-- initialization 
function init()
    -- set the speed of the robot to zero
    robot.wheels.set_velocity(0,0)
end

-- actions for each step
function step()

	log("To send: " .. FLOAT_NUMBER)

    -- each step, send the message
    send_message()
end

-- reinitialize the controller
function reset()
end

function destroy()
    -- put your code here
end

---------------------------------------------------------------------

-- sends the message via range and bearing
function send_message()

	-- indicate that it's a positive or negative float number
	set_positive_or_negative_message(FLOAT_NUMBER)

	-- variables
	begin_index = 2
	number = math.abs(FLOAT_NUMBER)
	exponent = 0
	is_exp_negative = 0

	-- make first number smaller than 1
	while number >= 1 do
		number = number / 10
		exponent = exponent + 1
	end

	-- as long as the number isn't zero, and if there is still room
	-- there is a value to send
	while not (number == 0) and begin_index + 2 <= 10 do

		-- calculate the following piece fitting in a byte
		while number * 10 <= 256 do
			number = number * 10
			exponent = exponent - 1
		end

		-- prepare sending values
		number_to_send = math.floor(number)
		is_exp_negative = is_negative(exponent)
		exponent_to_send = math.abs(exponent)

		-- send the values
		set_number_message(begin_index, number_to_send, is_exp_negative, exponent_to_send)
		
		-- prepare for next sending instruction
		begin_index = begin_index + 3
		number = number - number_to_send
	end
end

---------------------------------------------------------------------

-- returns 0 if number is positive,
-- returns 1 if number is negative
function is_negative(number)
	result = 0
	if number < 0 then
		result = 1
	end
	return result
end

---------------------------------------------------------------------

-- sets the first message to 1 if negative, 0 if positive
function set_positive_or_negative_message(number)
	index = 1
	set_message(index, 0)
end

-- sets the value, is_exp_negative and exponent values as messages
-- beginning from a given index
function set_number_message(begin_index, value, is_exp_negative, exponent)
	set_message(begin_index, value)
	set_message(begin_index + 1, is_exp_negative)
	set_message(begin_index + 2, exponent)
end

---------------------------------------------------------------------

function set_message(index, msg)
	robot.range_and_bearing.set_data(index, msg)
end
