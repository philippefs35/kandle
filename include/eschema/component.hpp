/*
 * MIT License
 *
 * Copyright (c) 2023 Harvey Bates
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

class Component {
public:

    // This information comes from the "DEF" identifier
    struct Definition {
        char name[50]{};
        char reference[25]{};
        int pin_name_offset{};
        char show_pin_number{};
        char show_pin_name{};
        int num_units{};
        char pwr_cmp{};
    };

    // This comes from F0 ... Fn
    struct Information {
        char text[50]{};
        int pos_x{};
        int pos_y{};
        int dimension{};
        char orientation{}; // H (horizontal) or V (vert)
        char visibility{}; // V (visible) or I (invisible)
        int font_size{};
        char horz_justification{};
        char vert_justification{};
        char italic{};
        char bold{};
        char field_name[50]{};
    };

    enum PinElectricalType : char {
        INPUT = 'I',
        OUTPUT = 'O',
        BIDIRECTIONAL = 'B',
        TRI_STATE = 'T',
        PASSIVE = 'P',
        UNSPECIFIED = 'U',
        POWER_INPUT = 'W',
        POWER_OUTPUT = 'w',
        OPEN_COLLECTOR = 'C',
        OPEN_EMITTER = 'E',
        NOT_CONNECTED = 'N'
    };

    struct Pin {
        char name[50]{};
        char number[4]{};
        int pos_x;
        int pos_y;
        int length;
        char orientation;
        int text_num_size;
        int text_name_size;
        int unit;
        int convert;
        char electric_type; // Input, output etc.
        // If shape[0] == 'N' then invisible
        char shape[4]{}; // Optional
    };

    struct Rectangle {
        int startx;
        int starty;
        int endx;
        int endy;
        int unit;
        int convert;
        int thickness;
        char background;
    };

    struct Polygon {
        int n_points;
        int parts;
        int convert;
        int thickness;
        int x0;
        int y0;
        int x1;
        int y1;
        int xi;
        int yi;
        char background;
    };

    struct Circle {
        int posx;
        int posy;
        int radius;
        int unit;
        int convert;
        int thickness;
        char background;
    };

    struct Arc {
        int posx;
        int posy;
        int radius;
        int start_angle;
        int end_angle;
        int part;
        int convert;
        int thickness;
        char background;
        int start_point_x;
        int start_point_y;
        int end_point_x;
        int end_point_y;
    };

    struct Text {
        int orientation;
        int posx;
        int posy;
        int dimension;
        int unit;
        int convert;
        char text[50]{};
    };
};
