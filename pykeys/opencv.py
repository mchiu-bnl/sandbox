#!/usr/bin/env python3
import cv2
import numpy as np

# Load the image of the key
key_image = cv2.imread('key_image.jpg')

# Convert to grayscale
gray = cv2.cvtColor(key_image, cv2.COLOR_BGR2GRAY)

# Use edge detection to detect the outline of the key
edges = cv2.Canny(gray, threshold1=100, threshold2=200)

# Find contours in the edge map
contours, hierarchy = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# Assuming the largest contour is the key itself, draw it
if contours:
    largest_contour = max(contours, key=cv2.contourArea)
    cv2.drawContours(key_image, [largest_contour], -1, (0, 255, 0), 3)

# Display the image with the key contour highlighted
cv2.imshow('Key Contour', key_image)
cv2.waitKey(0)
cv2.destroyAllWindows()

