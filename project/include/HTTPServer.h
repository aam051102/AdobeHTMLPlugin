/*************************************************************************
* ADOBE SYSTEMS INCORPORATED
* Copyright 2015 Adobe Systems Incorporated
* All Rights Reserved.

* NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance with the
* terms of the Adobe license agreement accompanying it.  If you have received this file from a
* source other than Adobe, then your use, modification, or distribution of it requires the prior
* written permission of Adobe.
**************************************************************************/

/**
 * @file  HTTPServer.h
 *
 * @brief This file contains the implementation for a HTTP server using Mongoose.
 */

#ifndef HTTP_SERVER_H_
#define HTTP_SERVER_H_

#ifdef USE_HTTP_SERVER

#include <string>
#include <memory>
#ifdef _WINDOWS
#include <xmemory>
#endif
#include "mongoose.h"
#include "FCMErrors.h"
#include "FCMTypes.h"

/* -------------------------------------------------- Forward Decl */


/* -------------------------------------------------- Enums */


/* -------------------------------------------------- Macros / Constants */


/* -------------------------------------------------- Structs / Unions */

struct ServerConfigParam
{
    std::string root;
    int port;
};

/* -------------------------------------------------- Class Decl */

namespace CreateJS
{
    class HTTPServer
    {
    public:
        static HTTPServer* GetInstance();
        virtual ~HTTPServer();

        FCM::Result Start();
        void Stop();

        void SetConfig(const ServerConfigParam& config);

    private:
        HTTPServer();

        static int BeginRequestHandler(struct mg_connection* conn);

    private:
        static std::auto_ptr<HTTPServer> m_instance;
        ServerConfigParam m_config;
        struct mg_context* m_context;
    };

};

#endif // USE_HTTP_SERVER

#endif // HTTP_SERVER_H_
