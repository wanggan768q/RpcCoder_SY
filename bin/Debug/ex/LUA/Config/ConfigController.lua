ConfigController = class("ConfigController",BaseController)

function ConfigController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ConfigController.new(ConfigModel:getInstance())
	end 
	return self.instance
end

function ConfigController:ctor(model)
	ConfigController.super.ctor(self,model)
	
	

end

function ConfigController:modelDataUpdate( syncId, idx )

end










