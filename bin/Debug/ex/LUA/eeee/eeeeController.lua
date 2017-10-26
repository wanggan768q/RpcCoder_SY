eeeeController = class("eeeeController",BaseController)

function eeeeController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=eeeeController.new(eeeeModel:getInstance())
	end 
	return self.instance
end

function eeeeController:ctor(model)
	eeeeController.super.ctor(self,model)
	
	

end

function eeeeController:modelDataUpdate( syncId, idx )

end










