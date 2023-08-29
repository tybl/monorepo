################################################################################
# License: The Unlicense (https://unlicense.org)
# vim:et:ts=2:sw=2
################################################################################

include(CheckCXXCompilerFlag)

function(add_warning_if_available compiler_flag)
  check_cxx_compiler_flag(-W${compiler_flag} HAS_COMPILER_FLAG_${COMPILER_FLAG})
  if (${HAS_COMPILER_FLAG_${COMPILER_FLAG}})
    add_compile_options(-W${compiler_flag})
  endif()
endfunction()

set(ALL_COMPILER_FLAGS
  address-of-packed-member
  all
  analyzer-allocation-size
  analyzer-deref-before-check
  analyzer-exposure-through-unint-copy
  analyzer-fd-access-mode-mismatch
  analyzer-fd-double-close
  analyzer-fd-leak
  analyzer-fd-phase-mismatch
  analyzer-fd-type-mismatch
  analyzer-fd-use-after-close
  analyzer-fd-use-without-check
  analyzer-imprecise-fp-arithmetic
  analyzer-infinite-recursion
  analyzer-jump-through-null
  analyzer-out-of-bounds
  analyzer-putenv-of-auto-var
  analyzer-tainted-assertion
  analyzer-use-of-uninitialized-value
  analyzer-write-to-const
  analyzer-write-to-string-literal
  arith-conversion
  array-bounds
  attribute-alias
  cast-align
  class-conversion
  conversion
  deprecated-copy
  deprecated-copy-dtor
  double-promotion
  duplicated-branches
  duplicated-cond
  #effc++
  extra
  #format-overflow
  #init-list-lifetime
  lifetime
  logical-op
  maybe-uninitialized
  misleading-indentation
  mismatched-tags
  #non-virtual-dtor
  #null-dereference
  old-style-cast
  overloaded-virtual
  pedantic
  redundant-tags
  restrict
  return-local-addr
  shadow
  sign-conversion
  stringop-overflow
  #suggest-attribute=const
  #suggest-attribute=pure
  uninitialized
  unused
  useless-cast
)

check_cxx_compiler_flag(-Weverything HAS_COMPILER_WARNING_everything)
if (${HAS_COMPILER_WARNING_everything})
  add_compile_options(-Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded)
else()
  foreach(COMPILER_FLAG ${ALL_COMPILER_FLAGS})
    add_warning_if_available(${COMPILER_FLAG})
  endforeach()
endif()
