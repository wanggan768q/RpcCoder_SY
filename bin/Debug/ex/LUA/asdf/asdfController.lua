asdfController = class("asdfController",BaseController)

function asdfController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=asdfController.new(asdfModel:getInstance())
	end 
	return self.instance
end

function asdfController:ctor(model)
	asdfController.super.ctor(self,model)
	
	

end

function asdfController:modelDataUpdate( syncId, idx )

end










