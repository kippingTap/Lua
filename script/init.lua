
local initSearchPath = function ()
	local paths = {
		";D:\\Visual Studio Projects\\Lua\\script\\?.lua",
		";D:\\Visual Studio Projects\\Lua\\res\\?.lua",
	};

	local pathStr = table.concat(paths)
	package.path = package.path .. pathStr;
end


local init = function ()
	--befor main
	initSearchPath();
	
	local ModUtil = require("funcUtil");
	ModUtil.open_util();

	--main entry
	local main = require("main");
	main();
end


init();