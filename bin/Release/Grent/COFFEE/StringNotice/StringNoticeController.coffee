
BaseController = require("./../../base/BaseController.coffee")
StringNoticeModel = require("./StringNoticeModel.coffee")



StringNoticeController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetNoticeNotifyCB(@NoticeCBNotify)

        return



    NoticeCBNotify:(ret_msg)->
        cc.log "NoticeCBNotify Respond "


)
StringNoticeController.getInstance = ->
    if this.instance is undefined
        model_ = StringNoticeModel
        model_.Initialize()
        this.instance = new StringNoticeController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = StringNoticeController.getInstance()
    controller_)()
  
