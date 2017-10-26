aaaaController = class("aaaaController",BaseController)

function aaaaController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=aaaaController.new(aaaaModel:getInstance())
	end 
	return self.instance
end

function aaaaController:ctor(model)
	aaaaController.super.ctor(self,model)
	
	

end

function aaaaController:modelDataUpdate( syncId, idx )

end










