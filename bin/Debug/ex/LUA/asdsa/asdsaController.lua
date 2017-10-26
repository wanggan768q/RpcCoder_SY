asdsaController = class("asdsaController",BaseController)

function asdsaController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=asdsaController.new(asdsaModel:getInstance())
	end 
	return self.instance
end

function asdsaController:ctor(model)
	asdsaController.super.ctor(self,model)
	
	

end

function asdsaController:modelDataUpdate( syncId, idx )

end










