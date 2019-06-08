


function ToCPP_string()
	return "ToCPP_string 你好";
end

function ToCPP_int()
	print("ToCPP_int lua");
	return 100;
end

function CPPTo_Lua(a,b,c)
	--CPPTo_Lua("一个消息测试","test",4)
	CPP_To_Lua(a,b,c)
end

function Main(p)
	print("Call Main");
	print(p);
	local ret = CPPTo_Lua("一个消息测试","test",4)
	print("ret "..ret);


	return 132456;
end
