[% USE raw %]
[% USE Koha %]
[% PROCESS 'html_helpers.inc' %]
<!-- z3950-admin-search.inc -->
[% WRAPPER tabs id="header_search" %]
    [% WRAPPER tab_panels %]
        [% WRAPPER tab_panel tabname="z3950_search" bt_active= 1 %]
            <form action="/cgi-bin/koha/admin/z3950servers.pl" method="get">
                <div class="form-title">
                    <label class="control-label" for="searchfield"><span class="control-text">Search Z39.50/SRU servers</span> <i class="fa fa-fw fa-search" aria-hidden="true"></i></label>
                </div>

                <div class="form-content">
                    <input class="head-searchbox form-control" type="text" name="searchfield" id="searchfield" value="[% searchfield | html %]" placeholder="Z39.50/SRU server search" />
                </div>
                <input type="hidden" name="op" value="search" />
                <button type="submit" aria-label="Search"><i class="fa fa-arrow-right"></i></button>
            </form>
        [% END # /tab_panel %]

        [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
            [% INCLUDE 'patron-search-box.inc' %]
        [% END %]
        [% IF ( CAN_user_catalogue ) %]
            [% INCLUDE 'catalogue-search-box.inc' %]
        [% END %]
    [% END # /tab_panels %]

    [% WRAPPER tabs_nav %]
        [% WRAPPER tab_item tabname= "z3950_search" bt_active= 1 %]
            <i class="fa fa-search" aria-hidden="true"></i> <span class="tab-title">Search Z39.50/SRU servers</span>
        [% END %]
        [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
            [% WRAPPER tab_item tabname= "circ_search" %]
                <i class="fa fa-upload" aria-hidden="true"></i> <span class="tab-title">Check out</span>
            [% END %]
        [% END %]
        [% IF ( CAN_user_catalogue ) %]
            [% WRAPPER tab_item tabname= "catalog_search" %]
                <i class="fa fa-fw fa-search" aria-hidden="true"></i> <span class="tab-title">Search catalog</span>
            [% END %]
        [% END %]
    [% END # /tabs_nav %]
[% END # /WRAPPER tabs %]
<!-- /z3950-admin-search.inc -->
