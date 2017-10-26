asdController = class("asdController",BaseController)

function asdController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=asdController.new(asdModel:getInstance())
	end 
	return self.instance
end

function asdController:ctor(model)
	asdController.super.ctor(self,model)
	
	

end

function asdController:modelDataUpdate( syncId, idx )

end










