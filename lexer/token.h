#pragma once
#include <string>
#include <map>
#include <vector>
namespace lexer
{
    enum TokenType
    {
        // eof
        tok_eof = EOF,

        // types
        tok_i32,
        tok_i64,
        tok_f32,
        tok_f64,
        tok_char,
        tok_string,
        tok_bool,

        // identifier
        tok_ident,

        // keywords
        tok_def,
        tok_extern,
        tok_let,
        tok_return,
        tok_if,
        tok_else,
        tok_void,
        tok_key_i32,
        tok_key_i64,
        tok_key_f32,
        tok_key_f64,
        tok_key_char,
        tok_key_string,
        tok_key_bool,

        // operators
        tok_lparenth,
        tok_rparenth,
        tok_lbracket,
        tok_rbracket,
        tok_lbrace,
        tok_rbrace,
        tok_semicolon,
        tok_colon,
        tok_assign,
        tok_eq,    // 2
        tok_notEq, // 2
        tok_bang,
        tok_asterisk,
        tok_plus,
        tok_minus,
        tok_slash,
        tok_comma,
        tok_less,
        tok_greater,
        tok_lessEq,    // 2
        tok_greaterEq, // 2

        tok_illegal,
    };

    static std::map<std::string, TokenType> keywordMap = {
        {"def", tok_def},
        {"extern", tok_extern},
        {"let", tok_let},
        {"return", tok_return},
        {"if", tok_if},
        {"else", tok_else},
        {"void", tok_void},
        {"i32", tok_key_i32},
        {"i64", tok_key_i64},
        {"f32", tok_key_f32},
        {"f64", tok_key_f64},
        {"char", tok_key_char},
        {"string", tok_key_string},
        {"bool", tok_key_bool}};

    static std::map<char, TokenType> opMap = {
        {'(', tok_lparenth},
        {')', tok_rparenth},
        {'{', tok_lbrace},
        {'}', tok_rbrace},
        {'[', tok_lbracket},
        {']', tok_rbracket},
        {';', tok_semicolon},
        {':', tok_colon},
        {'=', tok_assign},
        {'!', tok_bang},
        {'*', tok_asterisk},
        {'+', tok_plus},
        {'-', tok_minus},
        {'/', tok_slash},
        {',', tok_comma},
        {'<', tok_less},
        {'>', tok_greater}};

    class Token
    {
    public:
        Token(TokenType type, std::string literal);
        TokenType getType();
        std::string getLiteral();

    private:
        TokenType type;
        std::string literal;
    };
} // namespace lexer