/*
** EPITECH PROJECT, 2019
** logic.hpp
** File description:
** logic
*/

#ifndef LOGIC_HPP_
    #define LOGIC_HPP_

    // # Lib Imports

    #include <vector>
    #include <string>

    // # Local Imports

    #include "client.hpp"
    #include "logic/callHandler.hpp"
    #include "logic/entityHandler.hpp"

    enum logicEnum {
        Welcome = 0,
        Connect,
        SuccessConnect,
        FailConnect,
        Call,
        AcceptCall,
        HangUp,
        PendingRequest,
        PendingSuccess,
        PendingFail,
        PendingInfo,
        AcceptPending,
        RefusePending,
        AddContact,
        CallPart,
        CallAcceptCallBack
    };


#endif /* !LOGIC_HPP_ */