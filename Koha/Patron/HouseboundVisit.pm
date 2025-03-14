package Koha::Patron::HouseboundVisit;

# This file is part of Koha.
#
# Koha is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# Koha is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Koha; if not, see <http://www.gnu.org/licenses>.

use Modern::Perl;

use Koha::Database;
use Koha::Patron;

use base qw(Koha::Object);

=head1 NAME

Koha::Patron::HouseboundVisit - Koha Patron HouseboundVisit Object class

=head1 SYNOPSIS

HouseboundVisit class used primarily by members/housebound.pl.

=head1 DESCRIPTION

Standard Koha::Objects definitions, and additional methods.

=head1 API

=head2 Class Methods

=cut

=head3 chooser

  my $chooser = Koha::Patron::HouseboundVisit->chooser;

Returns the prefetched chooser for this visit.

=cut

sub chooser {
    my ($self) = @_;
    my $rs = $self->_result->chooser_brwnumber;
    return Koha::Patron->_new_from_dbic($rs);
}

=head3 deliverer

  my $deliverer = Koha::Patron::HouseboundVisit->deliverer;

Returns the prefetched deliverer for this visit.

=cut

sub deliverer {
    my ($self) = @_;
    my $rs = $self->_result->deliverer_brwnumber;
    return Koha::Patron->_new_from_dbic($rs);

}

=head3 _type

=cut

sub _type {
    return 'HouseboundVisit';
}

1;

=head1 AUTHOR

Alex Sassmannshausen <alex.sassmannshausen@ptfs-europe.com>

=cut
