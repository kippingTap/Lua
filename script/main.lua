
local Accout = require("accout")


local main = function ()
	print("Lua search path: \n", package.path)

	Accout.foo();


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
};
	
	local pi = 3.14159;
	local date = os.date();

	Log(" test log: t, pi, date ", t, pi, date);
end




return main;