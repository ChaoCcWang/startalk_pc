﻿//
// Created by cc on 2019-08-13.
//

#include "MessageManager.h"
#include <future>
#include "../EventBus/EventBus.h"
#include "LogicBase.h"
#include "../include/threadhelper.h"

void LogicBaseMsgManager::sendLoginProcessMessage(const std::string &message)
{
    bool status = false;
    LoginProcessMessage e(message, status);
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::sendLoginErrMessage(const std::string &message)
{
    LoginErrMessage e;
    e.errorMessage = message;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onAuthFailed(const std::string &message)
{
    AuthFailed e;
    e.message = message;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onDisconnectToServer()
{
    DisconnectToServer e;
    EventBus::FireEvent(e);
}

/**
 * 发送的消息被服务器拒绝(拉黑、 被踢出群聊)
 * @param messageFrom 对方id
 * @param messageId   消息id
 */
void LogicBaseMsgManager::recvBlackListMessage(const std::string &messageFrom, const std::string &messageId)
{
    R_BlackListMessage e;
    e.messageFrom = messageFrom;
    e.messageId = messageId;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::sendHttpReq(const QTalk::HttpRequest &request, const std::function<void(int, const std::string &)> &callback)
{
    S_AddHttpQeq e;
    e.request = request;
    e.callback = callback;
    EventBus::FireEvent(e);
}

/** socket */
void LogicBaseMsgManager::onRecvGroupMembers(const std::string &groupId, std::map<std::string, QUInt8> mapUserRole)
{
    S_RecvGroupMemberEvt e;
    e.groupId = groupId;
    e.mapUserRole = mapUserRole;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::creatGroupResult(const std::string &groupId, bool ret)
{
    CreatGroupRet e(groupId, ret);
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onInviteGroupMembers(const std::string &groupId)
{
    S_InviteGroupMemberEvt e;
    e.groupId = groupId;
    EventBus::FireEvent(e);
}

//void LogicBaseMsgManager::onGetFriends(const std::vector<QTalk::Entity::IMFriendList> &friends) {
//    S_AllFriendsEvt e;
//    e.friends = friends;
//    EventBus::FireEvent(e);
//}

void LogicBaseMsgManager::onDealBind()
{
    S_DealBind e;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onUpdateTimeStamp()
{
    S_UpdateTimeStamp e;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::LoginSuccess(const std::string &strSessionId)
{
    LoginSuccessMessage e;
    e.setSessionId(strSessionId);
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::synSeverData()
{
    SynSeverDataEvt e;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onUpdateGroupInfo(std::shared_ptr<QTalk::StGroupInfo> info)
{
    UpdateGroupInfoRet e;
    e.groupinfo = info;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onSwitchUserStatus(const std::string &status)
{
    SwitchUserStatusRet e(status);
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onUserConfigChanged()
{
    S_UserConfigChanged e;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onUserJoinGroup(const std::string &groupId, const std::string &memberId, int affiliation)
{
    S_UserJoinGroup e;
    e.groupId = groupId;
    e.memberJid = memberId;
    e.affiliation = affiliation;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onStaffChanged()
{
    S_StaffChanged e;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onFeedLog(const std::string &text)
{
    FeedBackLogEvt e(text);
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onDestroyGroup(const std::string &groupId, bool isDestroy)
{
    DestroyGroupRet e;
    e.groupId = groupId;
    e.isDestroy = isDestroy;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onRemoveGroupMember(const std::string &groupId, const std::string &memberId)
{
    RemoveGroupMemberRet e(groupId, memberId);
    EventBus::FireEvent(e);
}

void
LogicBaseMsgManager::updateRevokeMessage(const QTalk::Entity::UID &uid, const std::string &fromId,
        const string &messageId, const QInt64 &time)
{
    RevokeMessage e(uid, fromId, messageId);
    e.time = time;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::updateSignalChatReadState(const std::string &userId, const std::string &realJid, const std::map<std::string, QInt32> &readMasks)
{
    SignalReadState e( readMasks, userId, realJid);
    EventBus::FireEvent(e);
}

void
LogicBaseMsgManager::updateGroupChatReadState(const std::string &groupId, const std::map<std::string, int> &readedCount)
{
    GroupReadState e(readedCount, groupId);
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onGetHotLines()
{
    GetHotLines e;
    EventBus::FireEvent(e);
}

/**
 *
 * @param peerId
 */
void LogicBaseMsgManager::onRecvVideo(const std::string &peerId)
{
    RecvVideoMessage e(peerId);
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onRecvChatMessage(R_Message &e)
{
    EventBus::FireEvent(e);
}

void
LogicBaseMsgManager::updateMState(const std::string &userId, const std::string &realJid,
                                  const std::string &messageId, const QInt64 &time)
{
    MStateEvt evt;
    evt.time = time;
    evt.userId = userId;
    evt.realJid = realJid;
    evt.messageId = messageId;
    EventBus::FireEvent(evt);
}

void LogicBaseMsgManager::onRecvWebRtcCommand(int msgType, const std::string &jid, const std::string &command, bool isCarbon)
{
    WebRtcCommand e;
    e.msgType = msgType;
    e.cmd = command;
    e.jid = jid;
    e.isCarbon = isCarbon;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onMedalListChanged()
{
    SgMedalListChanged e;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::onUserMedalChanged()
{
    SgUserMedalChanged e;
    EventBus::FireEvent(e);
}

bool LogicBaseMsgManager::retryConnecToServer()
{
    RetryConnectToServerEvt e;
    EventBus::FireEvent(e);
    return e.result;
}

void LogicBaseMsgManager::refreshNav()
{
    RefreshNavEvt e;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::goBackLoginWnd(const std::string &reason)
{
    GoBackLoginWndEvt e;
    e.reason = reason;
    EventBus::FireEvent(e);
}

void LogicBaseMsgManager::systemQuit()
{
    SystemQuitEvt e;
    EventBus::FireEvent(e);
}

/** LogicBaseMsgListener **/
LogicBaseMsgListener::LogicBaseMsgListener(LogicBase *pLogicBase)
    : _pLogicBase(pLogicBase)
{
    EventBus::AddHandler<S_RevokeMessage>(*this);
    EventBus::AddHandler<SwitchUserStatusEvt>(*this);
    EventBus::AddHandler<ReadedMessage>(*this);
    EventBus::AddHandler<HeartBeat>(*this);
    EventBus::AddHandler<ForwardMessage>(*this);
    EventBus::AddHandler<S_Message>(*this);
    EventBus::AddHandler<PreSendMessageEvt>(*this);
    EventBus::AddHandler<SWebRtcCommand>(*this);
}

LogicBaseMsgListener::~LogicBaseMsgListener()
{
}

void LogicBaseMsgListener::onEvent(S_RevokeMessage &e)
{
    if (e.getCanceled())
        return;

    if (_pLogicBase)
        _pLogicBase->sendRovokeMessage(e.uid, e.messageFrom, e.messageId, e.chatType);
}


void LogicBaseMsgListener::onEvent(SwitchUserStatusEvt &e)
{
    if(_pLogicBase)
        _pLogicBase->switchUserStatus(e.user_status);
}

void LogicBaseMsgListener::onEvent(ReadedMessage &e)
{
    if (_pLogicBase)
        _pLogicBase->dealReadedMessage(e.messageId, e.userId, e.chatType);
}

void LogicBaseMsgListener::onEvent(HeartBeat &)
{
    if (_pLogicBase)
        _pLogicBase->sendHeartbeat();
}

/**
  * @函数名   onEvent
  * @功能描述 消息发送
  * @author   cc
  * @date     2018/09/19
  */
void LogicBaseMsgListener::onEvent(S_Message &e)
{
    if (nullptr != _pLogicBase)
        _pLogicBase->sendMessage(e.message);
}


void LogicBaseMsgListener::onEvent(ForwardMessage &e)
{
    if (_pLogicBase)
        _pLogicBase->forwardMessage(e.messageId, e.users);
}

void LogicBaseMsgListener::onEvent(PreSendMessageEvt &e)
{
    if(e.getCanceled()) return;

    auto helper = std::make_shared<ThreadHelper>();
    helper->run([this, e]()
    {
        if(_pLogicBase)
            _pLogicBase->parseSendMessageIntoDb(e.message, e.message.Type);
    });
}

void LogicBaseMsgListener::onEvent(SWebRtcCommand &e)
{
    if(_pLogicBase)
        _pLogicBase->sendWebRtcCommand(e.msgType, e.jid, e.cmd);
}