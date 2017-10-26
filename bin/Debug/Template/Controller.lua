$TEMPLATE$Controller = class("$TEMPLATE$Controller",BaseController)

function $TEMPLATE$Controller:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=$TEMPLATE$Controller.new($TEMPLATE$Model:getInstance())
	end 
	return self.instance
end

function $TEMPLATE$Controller:ctor(model)
	$TEMPLATE$Controller.super.ctor(self,model)
	
	
$INITCONTROLLER$
end

function $TEMPLATE$Controller:modelDataUpdate( syncId, idx )

end





$CONTROLLERCALLBACKFUNCTION$




