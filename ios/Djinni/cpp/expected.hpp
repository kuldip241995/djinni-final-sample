#pragma once

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#include <utility>
#include <type_traits>

#ifdef __cpp_lib_expected

#include <expected>

namespace djinni {

using ::std::expected;
using ::std::unexpected;

}

#else

#include "tl_expected.hpp"

namespace djinni {

using ::tl::unexpected;
using ::tl::expected;

}

#endif

namespace djinni {

template <class E>
djinni::unexpected<typename std::decay<E>::type> make_unexpected(E &&e) {
    return djinni::unexpected<typename std::decay<E>::type>(std::forward<E>(e));
}

}
