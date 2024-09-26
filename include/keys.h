/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:22:17 by oandelin          #+#    #+#             */
/*   Updated: 2024/09/26 15:28:37 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __APPLE__

enum e_keys {
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126,
	KEY_W = 13,
	KEY_S = 1,
	KEY_A = 0,
	KEY_Q = 12,
	KEY_SPACE = 49
};

#else

enum e_keys {
	KEY_ESC = 65307,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_DOWN = 65364,
	KEY_UP = 65362,
	KEY_W = 119,
	KEY_S = 115,
	KEY_A = 97,
	KEY_Q = 113,
	KEY_SPACE = 32
};

#endif
#endif