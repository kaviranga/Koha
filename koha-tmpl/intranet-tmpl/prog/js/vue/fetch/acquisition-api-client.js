import HttpClient from "./http-client";

export class AcquisitionAPIClient extends HttpClient {
    constructor() {
        super({
            baseURL: "/api/v1/acquisitions/",
        });
    }

    get vendors() {
        return {
            getAll: (query, params) =>
                this.getAll({
                    endpoint: "vendors",
                    query,
                    params: { _order_by: "name", ...params },
                    headers: {
                        "x-koha-embed": "aliases",
                    },
                }),
        };
    }
}

export default AcquisitionAPIClient;
