// include/core/middlewares/BaseMiddleware.hpp
#pragma once
#include <corogram/core/Middleware.hpp>

// Usage:
//
//   #include <corogram/core/middlewares/BaseMiddleware.hpp>
//
//   class MyMiddleware : public corogram::BaseMiddleware {
//   public:
//       drogon::Task<std::any> operator()(
//           corogram::NextFn next,
//           const corogram::Update& upd,
//           corogram::Context& ctx) override
//       {
//           LOG_INFO << "Before handler";
//           auto result = co_await next(upd, ctx);
//           LOG_INFO << "After handler";
//           co_return result;
//       }
//   };
//
//   // Dispatcher'a ekle:
//   dp.middleware(corogram::BaseMiddleware::make(std::make_shared<MyMiddleware>()));
//
//   // Observer'a ekle (sadece message için):
//   dp.message().outer_middleware(std::make_shared<MyMiddleware>());