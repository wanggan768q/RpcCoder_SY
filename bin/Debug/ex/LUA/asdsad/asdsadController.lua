asdsadController = class("asdsadController",BaseController)

function asdsadController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=asdsadController.new(asdsadModel:getInstance())
	end 
	return self.instance
end

function asdsadController:ctor(model)
	asdsadController.super.ctor(self,model)
	
	

end

function asdsadController:modelDataUpdate( syncId, idx )

end










