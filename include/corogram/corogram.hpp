#pragma once

#include <corogram/Types.hpp>
#include <corogram/Methods.hpp>
#include <corogram/Bot.hpp>
#include <corogram/BaseApi.hpp>

#include <corogram/utils/KeyboardBuilder.hpp>
#include <corogram/utils/Utf8Sanitize.hpp>

#include <corogram/Enums.hpp>
#include <corogram/Logger.hpp>

#include <corogram/core/Context.hpp>
#include <corogram/core/Dispatcher.hpp>
#include <corogram/core/Router.hpp>
#include <corogram/core/Observer.hpp>
#include <corogram/core/Middleware.hpp>
#include <corogram/core/middlewares/BaseMiddleware.hpp>
#include <corogram/core/middlewares/ErrorMiddleware.hpp>
#include <corogram/core/middlewares/UserContextMiddleware.hpp>

#include <corogram/core/ErrorEvent.hpp>
#include <corogram/core/ErrorObserver.hpp>
#include <corogram/core/filters/BaseFilter.hpp>
#include <corogram/core/filters/Filters.hpp>
#include <corogram/core/filters/MagicFilter.hpp>

#include <corogram/fsm/State.hpp>
#include <corogram/fsm/FSMContext.hpp>
#include <corogram/fsm/BaseStorage.hpp>
#include <corogram/fsm/MemoryStorage.hpp>
#include <corogram/fsm/RedisStorage.hpp>
#include <corogram/fsm/FSMMiddleware.hpp>
#include <corogram/fsm/StorageKey.hpp>
#include <corogram/fsm/StateFilter.hpp>

#include <corogram/network/BaseNetwork.hpp>
#include <corogram/network/DrogonNetwork.hpp>
#include <corogram/network/Exceptions.hpp>
#include <corogram/network/RequestMiddleware.hpp>
#include <corogram/network/WebhookServer.hpp>

/**
 * @mainpage
 * ### Overview
 * corogram is a modern C++20 Telegram bot framework built on Drogon.
 * Every part of the stack runs inside C++20 coroutines — no blocking threads, no callback pyramids.
 */