--
-- Author: wws
-- Date: 2015-11-26 11:00:40
--

local $TEMPLATE$Layer = class("$TEMPLATE$Layer", function()
    return require("app.layers.BaseLayer").new()
end)
$TEMPLATE$Layer.RESOURCE_FILENAME = "$TEMPLATE$Layer.csb"


$BUTTONTHING$

function $TEMPLATE$Layer:ctor()
$CTORLAYER$
$ENTERLAYER$	
end



function $TEMPLATE$Layer:onExit()

end

$ONENTERFUNCTIONS$


$ONENTERFUNCTIONSFUNCTION$


$FUNCTORLAYER$

return $TEMPLATE$Layer