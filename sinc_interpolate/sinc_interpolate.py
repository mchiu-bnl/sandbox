import numpy as np

def sinc(x):
    """Sinc function"""
    return np.sinc(x)

def windowed_sinc_interpolation(x, y, x_interp, window_width):
    """
    Perform windowed sinc interpolation.

    Parameters:
    - x: Input x values (1D array).
    - y: Input y values (1D array).
    - x_interp: X values at which to perform interpolation (1D array).
    - window_width: Width of the interpolation window.

    Returns:
    - Interpolated y values at x_interp (1D array).
    """

    interpolated_y = np.zeros_like(x_interp)

    for i, x_target in enumerate(x_interp):
        # Apply the windowing function to the sinc function
        windowed_sinc = sinc((x - x_target) / (window_width / 2))
        window = np.sinc((x - x_target) / (window_width / 2))

        # Perform the interpolation by summing the product of windowed sinc and y values
        interpolated_y[i] = np.sum(y * windowed_sinc) / np.sum(window)

    return interpolated_y

# Example usage:
if __name__ == "__main__":
    # Generate some example data
    x = np
