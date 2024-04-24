#include "algorithms/task/matrix_transposition.h"
#include "algorithms/task/convert_float.h"
#include "algorithms/task/evaluate_expression.h"
#include "algorithms/task/filter_word.h"
#include "algorithms/task/leave_longest_word.h"
#include "algorithms/task/rearrange_numbers.h"
#include "algorithms/task/remove_true_polynomial.h"
#include "algorithms/task/transpose_non_symmetric_matrix.h"
#include "algorithms/task/get_best_team.h"
#include "algorithms/task/update_product.h"


void test() {
    test_matrix_transpose();
    test_convert_float();
    test_evaluate();
    test_filter_word();
    test_leave_longest();
    test_remove_true_polynomial();
    test_rearrange_numbers();
    test_transpose_non_symmetric_matrix();
    test_get_best_team();
    test_update_product();
}


int main() {
    test();

    return 0;
}