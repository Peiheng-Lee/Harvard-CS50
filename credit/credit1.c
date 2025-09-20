#include <stdio.h>
#include <string.h>
#include <stdbool.h> // C99标准及以上，用于支持 bool 类型
#include <ctype.h>   // 用于检查字符是否为数字

/**
 * @brief 验证一个字符串数字是否符合鲁恩算法
 * * @param number_str 指向包含数字字符串的指针。字符串可以包含空格，但会被忽略。
 * @return 如果号码有效，返回 true；否则返回 false。
 */
bool isValidLuhn(const char *number_str) {
    if (number_str == NULL) {
        return false;
    }

    int sum = 0;
    int nDigits = 0;
    bool isSecond = false;

    // 从右向左遍历字符串
    for (int i = strlen(number_str) - 1; i >= 0; i--) {
        char c = number_str[i];

        int digit = c - '0'; // 将字符转换为整数

        if (isSecond) {
            digit *= 2;
            if (digit > 9) {
                digit = (digit / 10) + (digit % 10); // 或者 digit -= 9;
            }
        }

        sum += digit;
        isSecond = !isSecond; // 切换标志位
        nDigits++;
    }

    // 一个有效的号码至少要有两位数字
    if (nDigits < 2) {
        return false;
    }

    // 检查总和是否能被10整除
    return (sum % 10 == 0);
}

/**
 * @brief 为给定的数字串生成鲁恩算法的校验位
 * * @param base_number_str 指向不包含校验位的数字字符串的指针。
 * @return 返回计算出的校验位字符 ('0'-'9')。如果输入无效，则返回 '\0'。
 */
char generateLuhnCheckDigit(const char *base_number_str) {
    if (base_number_str == NULL) {
        return '\0';
    }

    // 附加一个 '0' 作为临时校验位，以便使用与验证相同的逻辑
    // 这样做可以简化计算过程
    char temp_number[strlen(base_number_str) + 2];
    sprintf(temp_number, "%s0", base_number_str);

    int sum = 0;
    bool isSecond = false; // 从右边（临时校验位'0'）开始，所以第一个要翻倍的是它左边的数字

    // 从右向左遍历，但不包括我们附加的'0'
    for (int i = strlen(temp_number) - 2; i >= 0; i--) {
        char c = temp_number[i];

        if (!isdigit(c)) {
            // 如果基础号码中包含非数字字符，则输入无效
            return '\0';
        }

        int digit = c - '0';

        // 注意：因为我们从右边的第二位开始，所以这里的 isSecond 初始值应为 true
        // 但由于循环从倒数第二位开始，isSecond 初始设为 false，循环内先切换再判断也可
        isSecond = !isSecond;
        if (isSecond) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }
        sum += digit;
    }

    // 计算校验位
    int checkDigit = (10 - (sum % 10)) % 10;

    return checkDigit + '0'; // 将整数校验位转换为字符
}


int main() {
    // --- 示例 1: 验证号码 ---
    const char *valid_card = "49927398716";
    const char *invalid_card = "49927398717";
    const char *card_with_spaces = "4992 7398 716";
    const char *short_card = "1";

    printf("--- 鲁恩算法验证 ---\n");
    printf("验证号码: %s -> %s\n", valid_card, isValidLuhn(valid_card) ? "有效 (Valid)" : "无效 (Invalid)");
    printf("验证号码: %s -> %s\n", invalid_card, isValidLuhn(invalid_card) ? "有效 (Valid)" : "无效 (Invalid)");
    printf("验证号码: %s -> %s\n", card_with_spaces, isValidLuhn(card_with_spaces) ? "有效 (Valid)" : "无效 (Invalid)");
    printf("验证号码: %s -> %s\n", short_card, isValidLuhn(short_card) ? "有效 (Valid)" : "无效 (Invalid)");
    printf("\n");

    // --- 示例 2: 生成校验位 ---
    const char *base_number = "4992739871";
    char check_digit = generateLuhnCheckDigit(base_number);

    printf("--- 鲁恩算法校验位生成 ---\n");
    if (check_digit != '\0') {
        printf("为 \"%s\" 生成的校验位是: %c\n", base_number, check_digit);

        // 构建完整号码并验证
        char full_number[strlen(base_number) + 2];
        sprintf(full_number, "%s%c", base_number, check_digit);
        printf("完整号码 \"%s\" 的验证结果: %s\n", full_number, isValidLuhn(full_number) ? "有效 (Valid)" : "无效 (Invalid)");
    } else {
        printf("为 \"%s\" 生成校验位失败，输入包含无效字符。\n", base_number);
    }

    return 0;
}
