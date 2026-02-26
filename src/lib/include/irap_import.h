#pragma once

#include "irap.h"
#include <filesystem>
#include <span>
#include <string_view>

namespace surfio::irap {
// convert from Fortran order to C order
inline size_t column_major_to_row_major_index(size_t idx, size_t ncol, size_t nrow) {
  return idx / ncol + (idx % ncol) * nrow;
}

irap from_ascii_file(const std::filesystem::path& file);
irap from_ascii_string(std::string_view buffer);
irap from_binary_file(const std::filesystem::path& file);
irap from_binary_buffer(std::span<const char> buffer);
} // namespace surfio::irap
