//
//  LexingAutomation.cpp
//  PPInterpreter
//
//  Created by Nikita Kartashov on 13/12/2013.
//  Copyright (c) 2013 Nikita Kartashov. All rights reserved.
//

#include "LexingAutomation.h"

#include "EmptyState.h"

LexingAutomation::LexingAutomation():
m_line(-1),
m_column(-1),
m_buffer(""),
m_state(new EmptyState()),
m_result(vector<Lexeme>())
{}

void LexingAutomation::set_result(Lexeme lexeme)
{
    m_result.push_back(lexeme);
}

void LexingAutomation::set_state(LexerState* state)
{
    delete m_state;
    m_state = state;
}

void LexingAutomation::clear_buffer()
{
    m_buffer = "";
}

void LexingAutomation::set_buffer(string value)
{
    m_buffer = value;
}

string LexingAutomation::get_buffer_prefix() const
{
    if (m_buffer.length() < 1)
        return "";
    return m_buffer.substr(0, m_buffer.length() - 1);
}

void LexingAutomation::set_buffer_to_last_char()
{
    m_buffer = m_buffer.substr(m_buffer.length() - 1);
}

void LexingAutomation::next_symbol(char symbol)
{
    ++m_column;
    m_buffer += symbol;
    m_state->next_state(*this, determine_symbol_type(symbol));
}

void LexingAutomation::next_line()
{
    m_column = -1;
    ++m_line;
    clear_buffer();
}

bool LexingAutomation::is_good()
{
    return m_state->get_is_good_state() == kOKState;
}