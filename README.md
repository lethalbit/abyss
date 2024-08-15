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

### Implementation Status

Abyss is still a very young library, so not much is implemented yet, and everything might not be.



#### Icon Key

Each header has two sections in it, the first is the status of that header, and the second are any note references that detail conditions or other important details.

<table>
	<tbody>
		<tr>
			<td colspan="3"><b>Concepts Library</b></td>
			<td colspan="3"><b>Dynamic Memory</b></td>
			<td colspan="3"><b>Localization Library</b></td>
		</tr>
		<tr>
			<td><code>concepts</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>memory</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>clocale</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td colspan="3"><b>Coroutine Library</b></td>
			<td><code>memory_resource</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>codecvt</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>coroutine</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>new</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>locale</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td colspan="3"><b>Utility Library</b></td>
			<td><code>scoped_allocator</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td colspan="3"><b>I/O Library</b></td>
		</tr>
		<tr>
			<td><code>any</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td colspan="3"><b>Numeric</b></td>
			<td><code>cstdio</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>bitset</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>cfloat</code></td>
			<td>:white_check_mark:</td>
			<td></td>
			<td><code>fstream</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>chrono</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>cinttypes</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>iomanip</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>compare</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>climits</code></td>
			<td>:white_check_mark:</td>
			<td></td>
			<td><code>ios</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>csetjump</code></td>
			<td>:x:</td>
			<td></td>
			<td><code>cstdint</code></td>
			<td>:white_check_mark:</td>
			<td></td>
			<td><code>iosfwd</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>csignal</code></td>
			<td>:x:</td>
			<td></td>
			<td><code>limits</code></td>
			<td>:white_check_mark:</td>
			<td></td>
			<td><code>iostream</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>cstdarg</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td colspan="3"><b>Error</b></td>
			<td><code>istream</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>cstddef</code></td>
			<td>:white_check_mark:</td>
			<td></td>
			<td><code>cassert</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>ostream</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>cstdlib</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>cerrno</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>print</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>ctime</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>exception</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>sstream</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>expected</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>stdexcept</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>streambuf</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>functional</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>system_error</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>strstream</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>initializer_list</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td colspan="3"><b>String Library</b></td>
			<td><code>syncstream</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>optional</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>cctype</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td colspan="3"><b>Filesystem Library</b></td>
		</tr>
		<tr>
			<td><code>source_location</code></td>
			<td>:white_check_mark:</td>
			<td></td>
			<td><code>charconv</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>filesystem</code></td>
			<td>:x:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>tuple</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>cstring</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td colspan="3"><b>Regex Library</b></td>
		</tr>
		<tr>
			<td><code>type_traits</code></td>
			<td>:construction:</td>
			<td></td>
			<td><code>cuchar</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>regex</code></td>
			<td>:x:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>typeindex</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>cwctype</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td colspan="3"><b>Atomic Library</b></td>
		</tr>
		<tr>
			<td><code>typeinfo</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>format</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>atomic</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>variant</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>string</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td colspan="3"><b>Thread Library</b></td>
		</tr>
		<tr>
			<td><code>version</code></td>
			<td>:construction:</td>
			<td></td>
			<td><code>string_view</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>thread</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td colspan="3"><b>Container Library</b></td>
			<td colspan="3"><b>Iterator Library</b></td>
			<td><code>stop_token</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>array</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>iterator</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>shared_mutex</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>deque</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td colspan="3"><b>Ranges Library</b></td>
			<td><code>semaphore</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>flat_map</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>ranges</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>mutex</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>flat_set</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td colspan="3"><b>Algorithm Library</b></td>
			<td><code>latch</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>forward_list</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>algorithm</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>future</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>list</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>execution</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>condition_variable</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>map</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td colspan="3"><b>Numerics Library</b></td>
			<td><code>barrier</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
		</tr>
		<tr>
			<td><code>mdspan</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>bit</code></td>
			<td>:white_check_mark:</td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td><code>queue</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>cfenv</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td><code>set</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>cmath</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td><code>span</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>complex</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td><code>stack</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>numbers</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td><code>unordered_map</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>numeric</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td><code>unordered_set</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>random</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td><code>vector</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td><code>ratio</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td></td>
			<td></td>
			<td></td>
			<td><code>valarray</code></td>
			<td>:hammer_and_wrench:</td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
	</tbody>
</table>

The key for the first section is as follows:

 * :construction: - In progress
 * :white_check_mark: - Completed
 * :hammer_and_wrench: - Planned, not started
 * :x: - Not-planned


## License

Abyss is licensed under the [BSD-3-Clause](https://spdx.org/licenses/BSD-3-Clause.html), the full text of which can be found in the [LICENSE](LICENSE) file.
