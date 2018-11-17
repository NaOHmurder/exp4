#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  work4.py
#  
#  Copyright 2018  <pi@raspberrypi>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#  


def main(args):
    return 0

if __name__ == '__main__':
    import sys
    import cv2
    cv2.namedWindow("orgin")
    img=cv2.imread("orgin.png",cv2.IMREAD_COLOR)
    cv2.imshow("orgin",img)
    element = cv2.getStructuringElement(cv2.MORPH_RECT,(15,15))
    dstimg=cv2.erode(img,element)
    cv2.namedWindow("new")
    cv2.imshow("new",dstimg)
    cv2.imwrite("new.jpg",dstimg)
    cv2.waitKey(0)
    sys.exit(main(sys.argv))
