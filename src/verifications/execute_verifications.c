/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_verifications.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:35:37 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/09 19:35:38 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	execute_verifications(t_data *data)
{
	if (!verify_rgb(data))
		exit_error(data, "Error: invalid color\n", 0);
	if (!verify_duplicate(&data->textures))
		exit_error(data, "Error: duplicate found\n", 0);
}
