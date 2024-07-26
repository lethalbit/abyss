# Abyss - Deeply Embeddable bare-metal C++ standard library

> [!CAUTION]
> This is a very young, and very experimental, don't rely on it for anything
> of importance or that's critical in nature.

Abyss is C++ standard library targeting embedded bare-metal applications. As such, it is not fully standards compliant due to missing a large chunk of runtime functionality. However, much effort has been made to try to make it as complete as possible.

There are also some non-standards compliant enhancements, such as making things `[[nodiscard]]` where they really should be, but were not done so by the standard.

### Supported Compilers

> [!INFORMATION]
> Due to the nature of the library, there is only a single version of the C++ standard
> that has been targeted, that being [C++20](https://wg21.link/std20), however some portions
> of [C++23](https://wg21.link/std23) have been backported where possible, as such a compiler
> with core language support for at lest C++20 is required.

Currently only G++ 13 or newer is supported, due to relying on some built-in internals the compiler provides.


## License

Abyss is licensed under the [BSD-3-Clause](https://spdx.org/licenses/BSD-3-Clause.html), the full text of which can be found in the [LICENSE](LICENSE) file.
