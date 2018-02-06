local t = {
	pi = 3.14159,
	address = "192.168.1.1:78",
	account = {
		name = "yanshuyu",
		balance = 464616516516115215,
		creditLevel = 5,
		familys = {
			"yyyyyy",
			"ssssss",
			"ttttttt",
		},
	},
	extend = {},

	op = function ( ... )
		print("hello world");
	end	

}




function table_to_string(t, sep)
	local table_content = "";
	table_content = sep .. "{";
	table_content = table_content .. "\n";

	local pairSep = sep .. sep;
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
			valueStr = "\n" .. table_to_string(v, newSep);
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



function print_table(tag, t, sep)
	sep = sep or " ";
	local s = table_to_string(t, sep);
	s = tag .. " = " .. "\n" .. s;
	print(s);
end


print_table("my table info", t);


print_table("string lib info", string);
