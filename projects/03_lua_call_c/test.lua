

function table_to_string(t, m, sep)
	local table_content = "";
	table_content = sep .. "{";
	table_content = table_content .. "\n";

	local pairSep = sep .. sep;
	
	if m then
		local mt = getmetatable(t);
		if mt and type(mt) == "table" then
			t.__meta = mt;
		end
	end


	for k, v in pairs(t) do
		local pairStr = "";

		--key string
		local keyStr = "";
		if type(k) == "string" then
			keyStr = "\""..tostring(k).."\"";
		else
			keyStr = tostring(k);
		end

		--value string
		local valueStr = "";
		if type(v) == "string" then
			valueStr = "\"" .. v .. "\"";
		elseif type(v) == "table" then
			local newSep = sep .. sep;
			valueStr = "\n" .. table_to_string(v, m, newSep);
		else 
			valueStr = tostring(v);
		end

		pairStr = pairSep .. keyStr .. " = " .. valueStr .. ",";
		pairStr = pairStr .. "\n";

		table_content = table_content .. pairStr;
	end

	table_content = table_content .. sep .. "}";
	
	return table_content;
end



function print_table(tag, t, m, sep)
	if type(t) ~= "table" then
		return " ";
	end
	local _m = m or false;
	local _sep = sep or " ";

	local s = table_to_string(t, _m, _sep);
	s = tag .. " = " .. "\n" .. s;
	print(s);
end





print("lua open myMath libs")

local x = mylib.add(3,4)
print("3+4 = ", x)


local y = mylib.div(3,0)
print("3/0 = ", y)


--print_table("my math libs", mylib)

local acc = Account.new();
Account.withdrawal(acc, 100);
Account.deposit(acc,1000);
print("fund : ", Account.getFund(acc));
Account.withdrawal(acc,50);
print("fund : ", Account.getFund(acc));
Account.delect(acc);
print("fund : ", Account.getFund(acc));

