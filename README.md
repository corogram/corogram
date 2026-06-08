# corogram

<div align="center">

**Modern C++20 Telegram Bot Framework**

*Fully async · Coroutine-native · Header-only · Drogon-powered*

[![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg)](https://en.cppreference.com/w/cpp/20)
[![Header-only](https://img.shields.io/badge/header--only-yes-brightgreen)](include/corogram)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Drogon](https://img.shields.io/badge/Drogon-%E2%89%A51.9-orange)](https://github.com/drogonframework/drogon)
[![Telegram Bot API](https://img.shields.io/badge/Bot%20API-10.0-blue.svg)](https://core.telegram.org/bots/api)

</div>

---

**corogram** is a C++20 Telegram bot framework built on [Drogon](https://github.com/drogonframework/drogon). Every part of the stack — handler dispatch, FSM storage, API calls, webhook handling — runs inside C++20 coroutines (`drogon::Task<T>`). No blocking threads, no callback pyramids.

```
Telegram ──► getUpdates / webhook POST
                    │
             Dispatcher.feed_update()
                    │
        outer middleware → router filters → inner middleware → handler
```

---

## Features

- **Long-polling & Webhook** — `dp.start_polling()` / `dp.start_webhook(cfg)`
- **24 update type observers** — `message`, `callback_query`, `inline_query`, `poll`, `chat_member`, and more
- **Filters (`F::`)** — `F::Command()`, `F::text()`, `F::photo()`, `F::private_chat()`, `F::State()`, `F::callback_data_prefix()`, operator `&&` / `||` / `!`
- **MagicFilter (`MF.`)** — fluent field access: `MF.text.contains("hi")`, `MF.from_user.id.eq(123LL)`, `MF.chat.type.eq("private")`
- **FSM** — `StatesGroup<T>`, `FSMContext`, `MemoryStorage`, `RedisStorage`
- **Routers** — composable sub-routers via `dp.include_router(router, {filters})`
- **Middlewares** — outer (before filters) and inner (after filters); lambda or class-based
- **Keyboard builders** — `InlineKeyboardBuilder`, `ReplyKeyboardBuilder`, `adjust(n)` layout engine
- **TextBuilder** — `Bold`, `Italic`, `Code`, `Pre`, `Link`, `Spoiler`; renders to HTML, MarkdownV2, or native `MessageEntity` list (UTF-16 offsets handled internally)
- **Deep links & payload** — `corogram::deep::create_start()`, base64url encode/decode, custom encoder support
- **Auth** — Login Widget HMAC-SHA-256, Mini App `init_data` verification, optional Ed25519
- **Logger** — named loggers, pluggable `LogSink`, ANSI colours out of the box

---

## Requirements

| Dependency                                          | Minimum     | Notes                                     |
| --------------------------------------------------- | ----------- | ----------------------------------------- |
| GCC / Clang                                         | ≥ 13 / ≥ 16 | C++20 coroutines required                 |
| CMake                                               | ≥ 3.20      |                                           |
| [Drogon](https://github.com/drogonframework/drogon) | ≥ 1.9       | async HTTP + event loop                   |
| [nlohmann/json](https://github.com/nlohmann/json)   | ≥ 3.11      | JSON parsing                              |
| hiredis                                             | ≥ 1.0       | Only for `RedisStorage`                   |
| OpenSSL                                             | any         | Login Widget HMAC, Mini App auth, Ed25519 |

---

## Installation

### Step 1 — Install dependencies

**Linux (apt)**

```bash
# Build tools & OpenSSL
sudo apt install build-essential cmake git libssl-dev

# nlohmann/json
sudo apt install nlohmann-json3-dev

# hiredis (optional — only needed for RedisStorage)
sudo apt install libhiredis-dev

# Drogon (not in apt — build from source)
sudo apt install libjsoncpp-dev uuid-dev zlib1g-dev
git clone --recurse-submodules https://github.com/drogonframework/drogon
cd drogon
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
sudo cmake --install build
```

**Windows (vcpkg)**

```powershell
vcpkg install drogon nlohmann-json openssl hiredis
```

Pass `-DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake` when configuring.

**macOS (Homebrew)**

```bash
brew install cmake openssl nlohmann-json hiredis
# Drogon from source (same steps as Linux above)
```

---

### Step 2 — Add corogram to your project

**Option A — add_subdirectory** *(clone into your tree)*

```bash
git clone https://github.com/corogram/corogram.git third_party/corogram
```

```cmake
# Your project's CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(my_bot)

add_subdirectory(third_party/corogram)

add_executable(my_bot main.cpp)
target_link_libraries(my_bot PRIVATE corogram::corogram)
```

**Option B — FetchContent** *(automatic download at configure time)*

```cmake
cmake_minimum_required(VERSION 3.20)
project(my_bot)

include(FetchContent)
FetchContent_Declare(corogram
    GIT_REPOSITORY https://github.com/corogram/corogram.git
    GIT_TAG        main
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(corogram)

add_executable(my_bot main.cpp)
target_link_libraries(my_bot PRIVATE corogram::corogram)
```

**Option C — system install** *(build & install once, then find_package)*

```bash
git clone https://github.com/corogram/corogram.git
cd corogram
cmake -B build -DCMAKE_BUILD_TYPE=Release
sudo cmake --install build
```

```cmake
find_package(corogram REQUIRED)
target_link_libraries(my_bot PRIVATE corogram::corogram)
```

---

### Step 3 — Build your project

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
./build/my_bot
```

> **Note:** `-fcoroutines` (GCC/Clang) and `/bigobj` (MSVC) are set automatically
> by `corogram::corogram` — you do **not** need to add them to your own target.

---

## Quick Start

```cpp
#include <corogram/corogram.hpp>
#include <drogon/drogon.h>
#include <cstdlib>
#include <iostream>

using namespace corogram;

int main()
{
    // make_network() returns a shared DrogonSession (HTTP backend).
    // Optional parameter: per-request timeout in seconds (default: 30).
    // One session can be shared across multiple Bot instances.
    
    auto session = make_network(/*timeout_sec=*/30.0);
    auto bot = std::make_shared<Bot>("YOUR_TOKEN_HERE", session);

    Dispatcher dp;
    dp.attach_bot(bot);
    dp.install_signal_handlers(); // graceful shutdown on SIGINT / SIGTERM

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_await bot->api().sendMessage(
                upd.message->chat->id,
                "Hello, " + upd.message->from->first_name + "!");
            co_return true;
        },
        {F::Command("start")});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_await bot->api().sendMessage(
                upd.message->chat->id, *upd.message->text);
            co_return true;
        },
        {F::text()});

    try
    {
        drogon::async_run([&dp]
                          { return dp.start_polling(); });
        drogon::app().run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "[error] " << e.what() << "\n";
        return 1;
    }
}
```

```bash
BOT_TOKEN="123456:ABC-DEF..." ./build/my_bot
```

---

## Project Layout

```
corogram/
├── include/
│   └── corogram/
│       ├── corogram.hpp              ← Single umbrella include
│       ├── Bot.hpp
│       ├── BaseApi.hpp
│       ├── Types.hpp                 ← All Telegram types (auto-generated)
│       ├── Methods.hpp               ← All Telegram API methods (auto-generated)
│       ├── Enums.hpp                 ← All Telegram enums (auto-generated)
│       ├── Logger.hpp
│       ├── core/
│       │   ├── Context.hpp
│       │   ├── Dispatcher.hpp
│       │   ├── Router.hpp
│       │   ├── Observer.hpp
│       │   ├── Middleware.hpp
│       │   ├── ErrorEvent.hpp
│       │   ├── ErrorObserver.hpp
│       │   ├── filters/
│       │   │   ├── BaseFilter.hpp
│       │   │   ├── Filters.hpp       ← F:: namespace
│       │   │   └── MagicFilter.hpp   ← MF. chainable filter
│       │   └── middlewares/
│       │       ├── BaseMiddleware.hpp
│       │       ├── ErrorMiddleware.hpp
│       │       └── UserContextMiddleware.hpp
│       ├── fsm/
│       │   ├── State.hpp
│       │   ├── FSMContext.hpp
│       │   ├── BaseStorage.hpp
│       │   ├── MemoryStorage.hpp
│       │   ├── RedisStorage.hpp
│       │   ├── FSMMiddleware.hpp
│       │   ├── StorageKey.hpp
│       │   └── StateFilter.hpp
│       ├── network/
│       │   ├── BaseNetwork.hpp
│       │   ├── DrogonNetwork.hpp
│       │   ├── Exceptions.hpp
│       │   ├── RequestMiddleware.hpp
│       │   └── WebhookServer.hpp
│       └── utils/
│           ├── KeyboardBuilder.hpp
│           ├── TextBuilder.hpp
│           ├── Link.hpp
│           ├── Markdown.hpp
│           ├── Auth.hpp
│           ├── WebAppAuth.hpp
│           └── Utf8Sanitize.hpp
├── cmake/
│   └── corogramConfig.cmake.in
├── examples/
│   ├── CMakeLists.txt
│   ├── echo_bot.cpp
│   ├── inline_keyboard.cpp
│   ├── reply_keyboard.cpp
│   ├── inline_query.cpp
│   ├── poll_bot.cpp
│   ├── fsm_form.cpp
│   ├── redis_fsm.cpp
│   ├── error_handling.cpp
│   ├── router_compose.cpp
│   ├── text_builder.cpp
│   ├── webhook_bot.cpp
│   ├── media_bot.cpp
│   └── chat_actions.cpp
└── CMakeLists.txt
```

---

## Core Concepts

### Dispatcher & Router

`Dispatcher` extends `Router` and is the root of the routing tree. Compose sub-routers with `include_router()`:

```cpp
auto admin = std::make_shared<Router>();
admin->message().register_handler(ban_handler, {F::Command("ban")});
dp.include_router(admin, {F::from_user(ADMIN_ID)});
```

### Handlers

Handlers are coroutines with signature `drogon::Task<bool>(const Update&, Context&)`. Return `true` to mark the update as handled (stops further routing), `false` to pass to the next handler.

```cpp
dp.message().register_handler(
    [](const Update &upd, Context &ctx) -> drogon::Task<bool>
    {
        auto *bot = ctx.get<Bot *>(ctx_keys::bot);
        co_await bot->api().sendMessage(upd.message->chat->id, "Hi!");
        co_return true;
    },
    {F::Command("hi")});
```

### Filters

```cpp
// Composition
dp.message().register_handler(handler, {F::private_chat() && F::Command("start")});
dp.message().register_handler(handler, {F::photo() || F::video()});
dp.message().register_handler(handler, {!F::is_bot()});

// MagicFilter
dp.message().register_handler(handler, {MF.from_user.language_code.eq("tr")});
dp.callback_query().register_handler(handler, {MF.callback_data.starts_with("menu_")});
```

### Middlewares

```cpp
// Outer — runs before filters (rate limiting, analytics)
dp.message().outer_middleware([](auto next, auto &upd, auto &ctx) -> drogon::Task<std::any> {
    std::cout << "Update received\n";
    co_return co_await next(upd, ctx);
});

// Inner — runs only when filters pass (DB session injection)
dp.message().middleware([](auto next, auto &upd, auto &ctx) -> drogon::Task<std::any> {
    ctx.set<std::shared_ptr<DbSession>>("db", pool->acquire());
    co_return co_await next(upd, ctx);
});
```

### FSM

```cpp
struct Form : corogram::fsm::StatesGroup<Form> {
    static inline auto waiting_name  = state("waiting_name");
    static inline auto waiting_email = state("waiting_email");
};

// Pass storage to Dispatcher — FSMMiddleware is installed automatically
auto storage = std::make_shared<corogram::fsm::MemoryStorage>();
Dispatcher dp(storage);

dp.message().register_handler(
    [](const Update &upd, Context &ctx) -> drogon::Task<bool>
    {
        auto &fsm = *ctx.get<std::shared_ptr<corogram::fsm::FSMContext>>("fsm");
        co_await fsm.update_data({{"name", *upd.message->text}});
        co_await fsm.set_state(Form::waiting_email.value());
        co_return true;
    },
    {F::State(Form::waiting_name), F::text()});
```

### Webhook

```cpp
WebhookConfig cfg;
cfg.url          = "https://yourdomain.com/bot";
cfg.path         = "/bot";
cfg.port         = 8443;
cfg.secret_token = "my_random_secret";  // always set in production

dp.start_webhook(std::move(cfg));
drogon::app().run();
```

Telegram's official IP ranges are filtered by default. Use `cfg.ip_filter = IPFilter::allow_all()` for local development behind a proxy.

---

### make_network

`make_network()` creates the HTTP backend that `Bot` uses for all Telegram API calls. It returns a `std::shared_ptr<DrogonSession>` which implements `INetwork`.

```cpp
// Default timeout (30 s)
auto session = corogram::make_network();

// Custom timeout
auto session = corogram::make_network(/*timeout_sec=*/10.0);

// One session can be shared across multiple Bot instances
auto bot1 = std::make_shared<Bot>(token1, session);
auto bot2 = std::make_shared<Bot>(token2, session);
```

`make_network()` is declared in `<corogram/network/DrogonNetwork.hpp>` and re-exported by the umbrella `<corogram/corogram.hpp>`.

---

### Utility Headers

All utilities are in the `corogram` namespace (or a sub-namespace) and included by `<corogram/corogram.hpp>`.

| Header                      | Namespace        | Purpose                                                                                                          |
| --------------------------- | ---------------- | ---------------------------------------------------------------------------------------------------------------- |
| `utils/TextBuilder.hpp`     | `corogram::fmt`  | `Bold`, `Italic`, `Code`, `Pre`, `Link`, `Spoiler` — renders to HTML, MarkdownV2, or native `MessageEntity` list |
| `utils/Markdown.hpp`        | `corogram::md`   | Escape helpers for MarkdownV2 strings                                                                            |
| `utils/KeyboardBuilder.hpp` | `corogram`       | `InlineKeyboardBuilder`, `ReplyKeyboardBuilder`, `adjust(n)`                                                     |
| `utils/Link.hpp`            | `corogram::deep` | `create_start()`, base64url encode/decode for deep links                                                         |
| `utils/Auth.hpp`            | `corogram::auth` | Login Widget HMAC-SHA-256 verification                                                                           |
| `utils/WebAppAuth.hpp`      | `corogram::auth` | Mini App `init_data` verification, optional Ed25519                                                              |
| `utils/Utf8Sanitize.hpp`    | `corogram`       | UTF-8 sanitizer used internally by TextBuilder                                                                   |

**TextBuilder example:**

```cpp
#include <corogram/utils/TextBuilder.hpp>
using namespace corogram::fmt;

auto text = Bold("Hello ") + Italic("world") + "\n" + Code("int x = 42;");
co_await bot->api().sendMessage(chat_id, text.html(), {.parse_mode = "HTML"});
// or: text.markdown_v2(), text.entities()
```

**Deep link example:**

```cpp
#include <corogram/utils/Link.hpp>
auto link = corogram::deep::create_start("my_bot", "ref_123");
// => "https://t.me/my_bot?start=cmVmXzEyMw"
```

---

## Examples

| File                  | Demonstrates                                                           |
| --------------------- | ---------------------------------------------------------------------- |
| `echo_bot.cpp`        | Basic polling, `make_network()`, send messages                         |
| `inline_keyboard.cpp` | `InlineKeyboardBuilder`, `callback_query` handler                      |
| `reply_keyboard.cpp`  | `ReplyKeyboardBuilder`, `remove_keyboard()`                            |
| `inline_query.cpp`    | `answerInlineQuery`, `InlineQueryResultArticle`                        |
| `poll_bot.cpp`        | `sendPoll`, `poll_answer` handler                                      |
| `fsm_form.cpp`        | Multi-step form with `MemoryStorage`                                   |
| `redis_fsm.cpp`       | FSM with `RedisStorage` + TTL *(requires hiredis)*                     |
| `error_handling.cpp`  | `dp.error()` observer, typed exception handling                        |
| `router_compose.cpp`  | Sub-routers, `include_router()`, `on_startup`                          |
| `text_builder.cpp`    | `TextBuilder` — HTML, MarkdownV2, native entities                      |
| `webhook_bot.cpp`     | Webhook mode, `WebhookConfig`                                          |
| `media_bot.cpp`       | `sendPhoto`, `sendDocument`, `sendMediaGroup`, `InputFile`             |
| `chat_actions.cpp`    | `sendChatAction`, `editMessageText`, `deleteMessage`, `pinChatMessage` |

Build examples:

```bash
cmake -B build -DCOROGRAM_BUILD_EXAMPLES=ON
cmake --build build -j$(nproc)
```

---

## CMake Options

| Option                    | Default | Description                                                                                 |
| ------------------------- | ------- | ------------------------------------------------------------------------------------------- |
| `COROGRAM_BUILD_EXAMPLES` | `OFF`   | Build all example binaries                                                                  |
| `COROGRAM_ED25519`        | `OFF`   | Ed25519 Mini App auth (requires OpenSSL)                                                    |
| `COROGRAM_HAS_HIREDIS`    | *auto*  | Force-enable (`ON`) or force-disable (`OFF`) hiredis/RedisStorage; auto-detected by default |

---

## Changelog

### v0.1.0 — Initial release

---

## Acknowledgements

corogram was built over approximately 4 months, drawing inspiration from the design and architecture of several existing Telegram bot frameworks:

- [aiogram](https://github.com/aiogram/aiogram) — Python async bot framework; the primary inspiration for the filter system (`F::`), MagicFilter (`MF.`), FSM design, middleware pipeline, and Router/Dispatcher architecture
- [python-telegram-bot](https://github.com/python-telegram-bot/python-telegram-bot) — `Update`/`Context` pattern and `effective_message`-style convenience accessors
- [TgBotCpp](https://github.com/egorpugin/tgbot) — C++ Telegram type/method code generation approach
- [tgbot-cpp](https://github.com/reo7sp/tgbot-cpp) — C++ API method structure
- [Drogon](https://github.com/drogonframework/drogon) — the async HTTP and coroutine foundation that makes corogram possible
- [nlohmann/json](https://github.com/nlohmann/json) — JSON serialization/deserialization


## License

MIT — see [LICENSE](LICENSE).