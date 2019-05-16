
BaseController = require("./../../base/BaseController.coffee")
BagModel = require("./BagModel.coffee")



BagController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetBagChangeNotifyCB(@BagChangeCBNotify)
        _model.SetAddItemNotifyCB(@AddItemCBNotify)
        _model.SetItemChangeNotifyCB(@ItemChangeCBNotify)

        return



    BagChangeCBNotify:(ret_msg)->
        cc.log "BagChangeCBNotify Respond "
    AddItemCBNotify:(ret_msg)->
        cc.log "AddItemCBNotify Respond "
    ItemChangeCBNotify:(ret_msg)->
        cc.log "ItemChangeCBNotify Respond "


)
BagController.getInstance = ->
    if this.instance is undefined
        model_ = BagModel
        model_.Initialize()
        this.instance = new BagController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = BagController.getInstance()
    controller_)()
  
