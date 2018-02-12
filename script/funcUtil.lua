local M = {};

M.table_to_string = function(t, m, sep)
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
			valueStr = "\n" .. M.table_to_string(v, m, newSep);
		elseif type(v) == "userdata" then 
			valueStr = M.userdata_to_string(u, m);
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



M.userdata_to_string = function (u, m)
	local uStr = tostring(u);
	local fmtStr = uStr;

	if m then
		local mt = getmetatable(u);
		if mt then
			local t = {
				ud = uStr;
				meta = mt;
			};

			fmtStr = table_to_string(t, true, " ");
		end
	end

	return fmtStr;
end




M.log_table = function(t, m, sep)
	local _m = m or true;
	local _sep = sep or " ";
	local s = M.table_to_string(t, _m, _sep);
	
	return s;
end


local log_userdata = function (u, m)
	m = m or true;
	local s = userdata_to_string(u, m);
	return s;
end


M.log_function = function (f)
	return tostring(f);
end


M.log_string = function (s)
	local fmtStr = "\"" .. s .. "\"";
	return fmtStr;
end


M.log_other = function (p)
	return tostring(p);
end



M.log = function ( tag, ... )
	local logStr = tag .. " = ";
	local paramStr = "";
	local sep = "\n";
	local params = {...};

	for _,param in pairs(params) do
		local typeName = type(param);
		local s = "";
		if typeName == "table" then
			s = M.log_table(param);

		elseif typeName == "userdata" then
			s = M.log_userdata(param);

		elseif typeName == "function" then
			s = M.log_function(param);
		elseif typeName == "string" then
			s = M.log_string(param);

		else
			s = M.log_other(param);
		end

		paramStr = paramStr .. s .. sep;
	end

	logStr = logStr .. paramStr;
	return logStr;
end


M.open_util = function ()

	_G.Log = function ( tag, ...)
		local logMsg = M.log(tag, ...);
		print(logMsg);
	end

end



return M;