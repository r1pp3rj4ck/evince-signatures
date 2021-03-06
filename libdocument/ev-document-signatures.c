/* ev-document-signatures.c
 *  this file is part of evince, a gnome document viewer
 *
 * Copyright © 2012 Vasco Dias  <contact@vascodias.me>
 *
 * Evince is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Evince is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

/**
 * SECTION: ev-document-signatures
 * @short_description: Interface that backends should implement for signatures support
 *
 * With this interface a backend can report if it supports digital signatures
 * and access the information on each signature availabe on a list.
 */
#include "config.h"

#include "ev-document-signatures.h"

G_DEFINE_INTERFACE (EvDocumentSignatures, ev_document_signatures, 0)

static void
ev_document_signatures_default_init (EvDocumentSignaturesInterface *klass)
{
}

/**
 * ev_document_signatures_has_signatures:
 * @document_signatures: an #EvDocumentSignatures
 *
 * Returns: if the document has digital signatures and they can be verified
 */
gboolean
ev_document_signatures_has_signatures (EvDocumentSignatures *document_signatures)
{
  EvDocumentSignaturesInterface *iface = EV_DOCUMENT_SIGNATURES_GET_IFACE (document_signatures);

  return iface->has_signatures (document_signatures);
}

/**
 * ev_document_signatures_get_signatures:
 * @document_signatures: an #EvDocumentSignatures
 *
 * Returns: A newly allocated #GList containing  newly allocated #EvSignature objects
 */
GList *
ev_document_signatures_get_signatures (EvDocumentSignatures *document_signatures)
{
  EvDocumentSignaturesInterface *iface = EV_DOCUMENT_SIGNATURES_GET_IFACE (document_signatures);

  return iface->get_signatures (document_signatures);
}
