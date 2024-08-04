# Abyss - Deeply Embeddable bare-metal C++ standard library

> [!CAUTION]
> This is a very young, and very experimental, don't rely on it for anything
> of importance or that's critical in nature.

Abyss is C++ standard library targeting embedded bare-metal applications. As such, it is not fully standards compliant due to missing a large chunk of runtime functionality. However, much effort has been made to try to make it as complete as possible.

There are also some non-standards compliant enhancements, such as making things `[[nodiscard]]` where they really should be, but were not done so by the standard.

### Supported Compilers

> [!IMPORTANT]
> Due to the nature of the library, there is only a single version of the C++ standard
> that has been targeted, that being [C++20](https://wg21.link/std20), however some portions
> of [C++23](https://wg21.link/std23) have been backported where possible, as such a compiler
> with core language support for at lest C++20 is required.

<table>
	<thead>
		<tr>
			<th>Compiler</th>
			<th colspan="3">G++</th>
			<th colspan="3">Clang++</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>Version</td>
			<td>12</td>
			<td>13</td>
			<td>14</td>
			<td>16</td>
			<td>17</td>
			<td>18</td>
		</tr>
		<tr></tr>
		<tr>
			<td>Supported</td>
			<td>:heavy_check_mark:</td>
			<td>:heavy_check_mark:</td>
			<td>:heavy_check_mark:</td>
			<td>:x:</td>
			<td>:heavy_check_mark:</td>
			<td>:heavy_check_mark:</td>
		</tr>
	</tbody>
</table>



## License

Abyss is licensed under the [BSD-3-Clause](https://spdx.org/licenses/BSD-3-Clause.html), the full text of which can be found in the [LICENSE](LICENSE) file.
