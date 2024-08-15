/* SPDX-License-Identifier: BSD-3-Clause */

#include <abyss/cstdint>
#include <abyss/bit>

// NOLINTNEXTLINE(readability-named-parameter)
int main(int, char**) {

	/* std::bit_cast */

	constexpr double d64{19880124.0};
	constexpr auto u64{std::bit_cast<std::uint64_t>(d64)};
	static_assert(std::bit_cast<double>(u64) == d64);

	/* std::byteswap */

	/* Because integer promotion is a fuck */
	static_assert(std::byteswap(std::uint8_t(0x34U)) == 0x43U);
	static_assert(std::byteswap(std::uint8_t(0x12U)) == 0x21U);
	static_assert(std::byteswap(std::uint8_t(0x24U)) == 0x42U);
	static_assert(std::byteswap(std::uint8_t(0x23U)) == 0x32U);

	static_assert(std::byteswap(std::uint16_t(0x3412U)) == 0x1234U);
	static_assert(std::byteswap(std::uint16_t(0x1234U)) == 0x3412U);
	static_assert(std::byteswap(std::uint16_t(0x2413U)) == 0x1324U);
	static_assert(std::byteswap(std::uint16_t(0x2143U)) == 0x4321U);

	static_assert(std::byteswap(0x78563412U) == 0x12345678U);
	static_assert(std::byteswap(0x12345678U) == 0x78563412U);
	static_assert(std::byteswap(0x34127856U) == 0x56781234U);
	static_assert(std::byteswap(0x56341278U) == 0x78123456U);

	static_assert(std::byteswap(0xEFCDAB8967452301LLU) == 0x0123456789ABCDEFLLU);
	static_assert(std::byteswap(0x0123456789ABCDEFLLU) == 0xEFCDAB8967452301LLU);
	static_assert(std::byteswap(0x89ABCDEF01234567LLU) == 0x67452301EFCDAB89LLU);
	static_assert(std::byteswap(0xAB8967452301EFCDLLU) == 0xCDEF0123456789ABLLU);

	/* std::popcount */

	static_assert(std::popcount(0b0000'0000U) == 0);
	static_assert(std::popcount(0b0000'0001U) == 1);
	static_assert(std::popcount(0b0000'0101U) == 2);
	static_assert(std::popcount(0b1100'0101U) == 4);

	static_assert(std::popcount(
		0b1100'0101'0000'0000U
	) == 4);
	static_assert(std::popcount(
		0b1100'0101'1010'0010U
	) == 7);
	static_assert(std::popcount(
		0b1101'0101'1010'0011U
	) == 9);
	static_assert(std::popcount(
		0b1101'1101'1010'0011U
	) == 10);

	static_assert(std::popcount(
		0b1101'1101'1010'0011'0011'0000'0000'0000U
	) == 12);
	static_assert(std::popcount(
		0b1101'1101'1010'0011'0101'0000'0100'0100U
	) == 14);
	static_assert(std::popcount(
		0b1101'1101'1010'0011'0110'1111'0000'0000U
	) == 16);
	static_assert(std::popcount(
		0b1101'1101'1010'0011'1111'0000'0000'1111U
	) == 18);

	static_assert(std::popcount(
		0b1101'1101'1010'0011'1111'0000'0000'1111'0000'0110'0000'0000'0110'0000'0000'0000U
	) == 22);
	static_assert(std::popcount(
		0b1101'1101'1010'0011'1111'0000'0000'1111'0000'0110'0000'0000'0110'0011'0000'1100U
	) == 26);
	static_assert(std::popcount(
		0b1101'1101'1010'0011'1111'0000'0000'1111'0110'0110'0000'0000'0110'0000'0000'1111U
	) == 28);
	static_assert(std::popcount(
		0b1101'1101'1010'0011'1111'0000'0000'1111'0110'0110'0000'0100'0110'0100'1000'0011U
	) == 29);

	/* std::has_single_bit */

	static_assert(!std::has_single_bit(0b0000'0000U));
	static_assert(std::has_single_bit(0b0001'0000U));
	static_assert(!std::has_single_bit(0b0011'0000U));
	static_assert(std::has_single_bit(0b0010'0000U));

	static_assert(!std::has_single_bit(0b0000'0000'0000'0000U));
	static_assert(std::has_single_bit(0b0001'0000'0000'0000U));
	static_assert(!std::has_single_bit(0b0011'0000'0000'0000U));
	static_assert(std::has_single_bit(0b0010'0000'0000'0000U));

	static_assert(!std::has_single_bit(0b0000'0000'0000'0000'0000'0000'0000'0000U));
	static_assert(std::has_single_bit(0b0001'0000'0000'0000'0000'0000'0000'0000U));
	static_assert(!std::has_single_bit(0b0011'0000'0000'0000'0000'0000'0000'0000U));
	static_assert(std::has_single_bit(0b0010'0000'0000'0000'0000'0000'0000'0000U));

	static_assert(!std::has_single_bit(0b0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000U));
	static_assert(std::has_single_bit(0b0001'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000U));
	static_assert(!std::has_single_bit(0b0011'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000U));
	static_assert(std::has_single_bit(0b0010'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000'0000U));

	/* std::countl_zero */

	static_assert(std::countl_zero(0b0000'0000'0000'0000'0000'0000'0000'0000U) == 32U);
	static_assert(std::countl_zero(0b0000'0000'0000'0000'0000'0000'0000'0001U) == 31U);
	static_assert(std::countl_zero(0b0000'0000'0000'0000'0000'0000'1000'0000U) == 24U);
	static_assert(std::countl_zero(0b0000'0000'0000'0000'1000'0000'0000'0000U) == 16U);
	static_assert(std::countl_zero(0b0000'0000'1000'0000'0000'0000'0000'0000U) ==  8U);
	static_assert(std::countl_zero(0b0000'1000'0000'0000'0000'0000'0000'0000U) ==  4U);
	static_assert(std::countl_zero(0b0010'0000'0000'0000'0000'0000'0000'0000U) ==  2U);
	static_assert(std::countl_zero(0b1000'0000'0000'0000'0000'0000'0000'0000U) ==  0U);

	/* std::countl_one */

	static_assert(std::countl_one(0b0000'0000'0000'0000'0000'0000'0000'0000U) ==  0U);
	static_assert(std::countl_one(0b1000'0000'0000'0000'0000'0000'0000'0000U) ==  1U);
	static_assert(std::countl_one(0b1100'0000'0000'0000'0000'0000'1000'0000U) ==  2U);
	static_assert(std::countl_one(0b1110'0000'0000'0000'0000'0000'0000'0000U) ==  3U);
	static_assert(std::countl_one(0b1111'0000'0000'0000'0000'0000'0000'0000U) ==  4U);
	static_assert(std::countl_one(0b1111'1111'0000'0000'0000'0000'0000'0000U) ==  8U);
	static_assert(std::countl_one(0b1111'1111'1111'1111'0000'0000'0000'0000U) == 16U);
	static_assert(std::countl_one(0b1111'1111'1111'1111'1111'1111'1111'1111U) == 32U);

	/* std::countr_zero */

	static_assert(std::countr_zero(0b0000'0000'0000'0000'0000'0000'0000'0000U) == 32U);
	static_assert(std::countr_zero(0b0000'0000'0000'0000'0000'0000'0000'0001U) ==  0U);
	static_assert(std::countr_zero(0b0000'0000'0000'0000'0000'0000'1000'0000U) ==  7U);
	static_assert(std::countr_zero(0b0000'0000'0000'0000'1000'0000'0000'0000U) == 15U);
	static_assert(std::countr_zero(0b0000'0000'1000'0000'0000'0000'0000'0000U) == 23U);
	static_assert(std::countr_zero(0b0000'1000'0000'0000'0000'0000'0000'0000U) == 27U);
	static_assert(std::countr_zero(0b0010'0000'0000'0000'0000'0000'0000'0000U) == 29U);
	static_assert(std::countr_zero(0b1000'0000'0000'0000'0000'0000'0000'0000U) == 31U);

	/* std::countr_one */

	static_assert(std::countr_one(0b0000'0000'0000'0000'0000'0000'0000'0000U) ==  0U);
	static_assert(std::countr_one(0b0000'0000'0000'0000'0000'0000'0000'0001U) ==  1U);
	static_assert(std::countr_one(0b0000'0000'0000'0000'0000'0000'0000'0011U) ==  2U);
	static_assert(std::countr_one(0b0000'0000'0000'0000'0000'0000'0000'0111U) ==  3U);
	static_assert(std::countr_one(0b0000'0000'0000'0000'0000'0000'0000'1111U) ==  4U);
	static_assert(std::countr_one(0b0000'0000'0000'0000'0000'0000'1111'1111U) ==  8U);
	static_assert(std::countr_one(0b0000'0000'0000'0000'1111'1111'1111'1111U) == 16U);
	static_assert(std::countr_one(0b1111'1111'1111'1111'1111'1111'1111'1111U) == 32U);

	/* std::rotl */

	static_assert(std::rotl(std::uint8_t(0b1100'1010U), -4) == 0b1010'1100U);
	static_assert(std::rotl(std::uint8_t(0b1100'1010U), -3) == 0b0101'1001U);
	static_assert(std::rotl(std::uint8_t(0b1100'1010U), -2) == 0b1011'0010U);
	static_assert(std::rotl(std::uint8_t(0b1100'1010U), -1) == 0b0110'0101U);
	static_assert(std::rotl(std::uint8_t(0b1100'1010U),  0) == 0b1100'1010U);
	static_assert(std::rotl(std::uint8_t(0b1100'1010U),  1) == 0b1001'0101U);
	static_assert(std::rotl(std::uint8_t(0b1100'1010U),  2) == 0b0010'1011U);
	static_assert(std::rotl(std::uint8_t(0b1100'1010U),  3) == 0b0101'0110U);
	static_assert(std::rotl(std::uint8_t(0b1100'1010U),  4) == 0b1010'1100U);

	/* std::rotr */

	static_assert(std::rotr(std::uint8_t(0b1100'1010U), -4) == 0b1010'1100U);
	static_assert(std::rotr(std::uint8_t(0b1100'1010U), -3) == 0b0101'0110U);
	static_assert(std::rotr(std::uint8_t(0b1100'1010U), -2) == 0b0010'1011U);
	static_assert(std::rotr(std::uint8_t(0b1100'1010U), -1) == 0b1001'0101U);
	static_assert(std::rotr(std::uint8_t(0b1100'1010U),  0) == 0b1100'1010U);
	static_assert(std::rotr(std::uint8_t(0b1100'1010U),  1) == 0b0110'0101U);
	static_assert(std::rotr(std::uint8_t(0b1100'1010U),  2) == 0b1011'0010U);
	static_assert(std::rotr(std::uint8_t(0b1100'1010U),  3) == 0b0101'1001U);
	static_assert(std::rotr(std::uint8_t(0b1100'1010U),  4) == 0b1010'1100U);

	/* std::bit_ceil */

	static_assert(std::bit_ceil(0b0000'0000U) == 0b0000'0001U);
	static_assert(std::bit_ceil(0b0000'0001U) == 0b0000'0001U);
	static_assert(std::bit_ceil(0b0000'0010U) == 0b0000'0010U);
	static_assert(std::bit_ceil(0b0000'0011U) == 0b0000'0100U);
	static_assert(std::bit_ceil(0b0000'1001U) == 0b0001'0000U);


	/* std::bit_floor */

	static_assert(std::bit_floor(0b0000'0000U) == 0b0000'0000U);
	static_assert(std::bit_floor(0b0000'0010U) == 0b0000'0010U);
	static_assert(std::bit_floor(0b0000'0011U) == 0b0000'0010U);
	static_assert(std::bit_floor(0b0000'1011U) == 0b0000'1000U);
	static_assert(std::bit_floor(0b0000'1111U) == 0b0000'1000U);
	static_assert(std::bit_floor(0b0100'1111U) == 0b0100'0000U);

	/* std::bit_width */

	static_assert(std::bit_width(0b0000'0000U) == 0U);
	static_assert(std::bit_width(0b0000'0010U) == 2U);
	static_assert(std::bit_width(0b0000'0011U) == 2U);
	static_assert(std::bit_width(0b0000'1011U) == 4U);
	static_assert(std::bit_width(0b0010'1011U) == 6U);

	return 0;
}
